#pragma once

#include "DiabloUI/art.h"
#include "engine.h"

namespace devilution {

void DrawArt(Point screenPosition, Art *art, int nFrame = 0, Uint16 srcW = 0, Uint16 srcH = 0);

void DrawArt(const Surface &out, Point screenPosition, Art *art, int nFrame = 0, Uint16 srcW = 0, Uint16 srcH = 0, bool updatePalette = true);

void DrawAnimatedArt(Art *art, Point screenPosition);

int GetAnimationFrame(int frames, int fps = 60);

} // namespace devilution
