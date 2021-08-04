/**
 * @file text_render.cpp
 *
 * Text rendering.
 */
#include "text_render.hpp"

#include <array>
#include <utility>

#include "DiabloUI/art_draw.h"
#include "DiabloUI/ui_item.h"
#include "cel_render.hpp"
#include "engine.h"
#include "engine/load_cel.hpp"
#include "engine/point.hpp"
#include "palette.h"
#include "engine/load_file.hpp"
#include "DiabloUI/diabloui.h"
#include "utils/display.h"
#include "utils/sdl_compat.h"

namespace devilution {

namespace {

std::array<int, 6> FontSizes = {
	12,
	16,
	24,
	30,
	42,
	46,
};
std::array<Art, 6> Fonts;
std::array<std::array<uint8_t, 256>, 6> FontKerns;

enum text_color : uint8_t {
	ColorWhite,
	ColorSilver,
	ColorGold,
	ColorRed,
	ColorBlue,
	ColorBlack,
};

int LineHeights[6] = { 12, 16, 26, 38, 42, 50 };
int BaseLineOffset[6] = { -2, -4, -2, -3, -6, -7 };

std::array<std::array<SDL_Color, 256>, 6> FontColorTables;
int PaletteOffset;

} // namespace

std::optional<CelSprite> pSPentSpn2Cels;

void InitText(int paletteOffset)
{
	for (int i = 0; i < 6; i++) {
		char path[32];
		sprintf(path, "fonts\\%i-00.pcx", FontSizes[i]);

		LoadMaskedArt(path, &Fonts[i], 256, 1);

		sprintf(path, "fonts\\%i-00.bin", FontSizes[i]);
		LoadFileInMem(path, FontKerns[i]);
	}

	pSPentSpn2Cels = LoadCel("Data\\PentSpn2.CEL", 12);

	PaletteOffset = paletteOffset;
}

void UnloadFonts()
{
	for (auto &font : Fonts) {
		font.Unload();
	}
}

void UpdateFontColors()
{
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorWhite][i] = system_palette[i + 46 + PaletteOffset];
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorSilver][i] = system_palette[i + 44 + PaletteOffset];
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorBlue][i] = system_palette[i - 17 + PaletteOffset];
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorRed][i] = system_palette[i + 30 + PaletteOffset];
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorGold][i] = system_palette[i + PaletteOffset];
	for (int i = 194; i < 207; i++)
		FontColorTables[ColorBlack][i] = system_palette[0];
}

int GetLineWidth(string_view text, GameFontTables size, int spacing, int *charactersInLine)
{
	int lineWidth = 0;

	size_t i = 0;
	for (; i < text.length(); i++) {
		if (text[i] == '\n')
			break;

		uint8_t frame = text[i] & 0xFF;
		lineWidth += FontKerns[size][frame] + spacing;
	}

	if (charactersInLine != nullptr)
		*charactersInLine = i;

	return lineWidth != 0 ? (lineWidth - spacing) : 0;
}

int AdjustSpacingToFitHorizontally(int &lineWidth, int maxSpacing, int charactersInLine, int availableWidth)
{
	if (lineWidth <= availableWidth || charactersInLine < 2)
		return maxSpacing;

	const int overhang = lineWidth - availableWidth;
	const int spacingRedux = (overhang + charactersInLine - 2) / (charactersInLine - 1);
	lineWidth -= spacingRedux * (charactersInLine - 1);
	return maxSpacing - spacingRedux;
}

void WordWrapString(char *text, size_t width, GameFontTables size, int spacing)
{
	const size_t textLength = strlen(text);
	size_t lineStart = 0;
	size_t lineWidth = 0;
	for (unsigned i = 0; i < textLength; i++) {
		if (text[i] == '\n') { // Existing line break, scan next line
			lineStart = i + 1;
			lineWidth = 0;
			continue;
		}

		uint8_t frame = text[i] & 0xFF;
		lineWidth += FontKerns[size][frame] + spacing;

		if (lineWidth - spacing <= width) {
			continue; // String is still within the limit, continue to the next line
		}

		size_t j; // Backtrack to the previous space
		for (j = i; j > lineStart; j--) {
			if (text[j] == ' ') {
				break;
			}
		}

		if (j == lineStart) { // Single word longer than width
			if (i == textLength)
				break;
			j = i;
		}

		// Break line and continue to next line
		i = j;
		text[i] = '\n';
		lineStart = i + 1;
		lineWidth = 0;
	}
}

/**
 * @todo replace Rectangle with cropped Surface
 */
uint32_t DrawString(const Surface &out, string_view text, const Rectangle &rect, UiFlags flags, int spacing, int lineHeight, bool drawTextCursor)
{
	GameFontTables size = GameFont12;
	if (HasAnyOf(flags, UiFlags::FontSize16))
		size = GameFont16;
	else if (HasAnyOf(flags, UiFlags::FontSize24))
		size = GameFont24;
	else if (HasAnyOf(flags, UiFlags::FontSize30))
		size = GameFont30;
	else if (HasAnyOf(flags, UiFlags::FontSize42))
		size = GameFont42;
	else if (HasAnyOf(flags, UiFlags::FontSize46))
		size = GameFont46;

	text_color color = ColorGold;
	if (HasAnyOf(flags, UiFlags::ColorWhite))
		color = ColorWhite;
	else if (HasAnyOf(flags, UiFlags::ColorSilver))
		color = ColorSilver;
	else if (HasAnyOf(flags, UiFlags::ColorBlue))
		color = ColorBlue;
	else if (HasAnyOf(flags, UiFlags::ColorRed))
		color = ColorRed;
	else if (HasAnyOf(flags, UiFlags::ColorBlack))
		color = ColorBlack;

	int charactersInLine = 0;
	int lineWidth = 0;
	if (HasAnyOf(flags, (UiFlags::AlignCenter | UiFlags::AlignRight | UiFlags::KerningFitSpacing)))
		lineWidth = GetLineWidth(text, size, spacing, &charactersInLine);

	int maxSpacing = spacing;
	if (HasAnyOf(flags, UiFlags::KerningFitSpacing))
		spacing = AdjustSpacingToFitHorizontally(lineWidth, maxSpacing, charactersInLine, rect.size.width);

	Point characterPosition = rect.position;
	if (HasAnyOf(flags, UiFlags::AlignCenter))
		characterPosition.x += (rect.size.width - lineWidth) / 2;
	else if (HasAnyOf(flags, UiFlags::AlignRight))
		characterPosition.x += rect.size.width - lineWidth;

	int rightMargin = rect.position.x + rect.size.width;
	int bottomMargin = rect.size.height != 0 ? rect.position.y + rect.size.height : out.h();

	if (lineHeight == -1)
		lineHeight = LineHeights[size];

	if (HasAnyOf(flags, UiFlags::VerticalCenter)) {
		int textHeight = (std::count(text.cbegin(), text.cend(), '\n') + 1) * lineHeight;
		characterPosition.y += (rect.size.height - textHeight) / 2;
	}

	characterPosition.y += BaseLineOffset[size];

	if (SDLC_SetSurfaceColors(Fonts[size].surface.get(), &FontColorTables[color][0], 0, 256) <= -1)
		ErrSdl();

	uint32_t i = 0;
	for (; i < text.length(); i++) {
		uint8_t frame = text[i] & 0xFF;
		int symbolWidth = FontKerns[size][frame];
		if (text[i] == '\n' || characterPosition.x + symbolWidth > rightMargin) {
			if (characterPosition.y + lineHeight >= bottomMargin)
				break;
			characterPosition.y += lineHeight;

			if (HasAnyOf(flags, (UiFlags::AlignCenter | UiFlags::AlignRight | UiFlags::KerningFitSpacing)))
				lineWidth = GetLineWidth(&text[i + 1], size, spacing, &charactersInLine);

			if (HasAnyOf(flags, UiFlags::KerningFitSpacing))
				spacing = AdjustSpacingToFitHorizontally(lineWidth, maxSpacing, charactersInLine, rect.size.width);

			characterPosition.x = rect.position.x;
			if (HasAnyOf(flags, UiFlags::AlignCenter))
				characterPosition.x += (rect.size.width - lineWidth) / 2;
			else if (HasAnyOf(flags, UiFlags::AlignRight))
				characterPosition.x += rect.size.width - lineWidth;
		}
		DrawArt(out, { characterPosition.x, characterPosition.y }, &Fonts[size], frame, 0, 0, false);
		if (text[i] != '\n')
			characterPosition.x += symbolWidth + spacing;
	}
	if (drawTextCursor) {
		CelDrawTo(out, characterPosition, *pSPentSpn2Cels, PentSpn2Spin());
	}

	return i;
}

uint8_t PentSpn2Spin()
{
	return (SDL_GetTicks() / 50) % 8 + 1;
}

} // namespace devilution
