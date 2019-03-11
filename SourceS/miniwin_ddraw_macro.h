#define _FACDD 0x876
#define MAKE_DDHRESULT(code) MAKE_HRESULT(1, _FACDD, code)

#define DDERR_SURFACELOST MAKE_DDHRESULT(450)
#define DDERR_WASSTILLDRAWING MAKE_DDHRESULT(540)
#define DDERR_SURFACEBUSY MAKE_DDHRESULT(430)
/*
 * returned when the position of the overlay on the destionation is no longer
 * legal for that destionation.
 */
#define DDERR_INVALIDPOSITION MAKE_DDHRESULT(579)

#define DDERR_ALREADYINITIALIZED MAKE_DDHRESULT(5)
#define DDERR_BLTFASTCANTCLIP MAKE_DDHRESULT(574)
#define DDERR_CANNOTATTACHSURFACE MAKE_DDHRESULT(10)
#define DDERR_CANNOTDETACHSURFACE MAKE_DDHRESULT(20)
#define DDERR_CANTCREATEDC MAKE_DDHRESULT(585)
#define DDERR_CANTDUPLICATE MAKE_DDHRESULT(583)
#define DDERR_CANTLOCKSURFACE MAKE_DDHRESULT(435)
#define DDERR_CANTPAGELOCK MAKE_DDHRESULT(640)
#define DDERR_CANTPAGEUNLOCK MAKE_DDHRESULT(660)
#define DDERR_CLIPPERISUSINGHWND MAKE_DDHRESULT(567)
#define DDERR_COLORKEYNOTSET MAKE_DDHRESULT(400)
#define DDERR_CURRENTLYNOTAVAIL MAKE_DDHRESULT(40)
#define DDERR_DCALREADYCREATED MAKE_DDHRESULT(620)
#define DDERR_DIRECTDRAWALREADYCREATED MAKE_DDHRESULT(562)
#define DDERR_EXCEPTION MAKE_DDHRESULT(55)
#define DDERR_EXCLUSIVEMODEALREADYSET MAKE_DDHRESULT(581)
#define DDERR_GENERIC E_FAIL
#define DDERR_HEIGHTALIGN MAKE_DDHRESULT(90)
#define DDERR_HWNDALREADYSET MAKE_DDHRESULT(571)
#define DDERR_HWNDSUBCLASSED MAKE_DDHRESULT(570)
#define DDERR_IMPLICITLYCREATED MAKE_DDHRESULT(588)
#define DDERR_INCOMPATIBLEPRIMARY MAKE_DDHRESULT(95)
#define DDERR_INVALIDCAPS MAKE_DDHRESULT(100)
#define DDERR_INVALIDCLIPLIST MAKE_DDHRESULT(110)
#define DDERR_INVALIDDIRECTDRAWGUID MAKE_DDHRESULT(561)
#define DDERR_INVALIDMODE MAKE_DDHRESULT(120)
#define DDERR_INVALIDOBJECT MAKE_DDHRESULT(130)
#define DDERR_INVALIDPARAMS 0x80070057
#define DDERR_INVALIDPIXELFORMAT MAKE_DDHRESULT(145)
#define DDERR_INVALIDPOSITION MAKE_DDHRESULT(579)
#define DDERR_INVALIDRECT MAKE_DDHRESULT(150)
#define DDERR_INVALIDSURFACETYPE MAKE_DDHRESULT(592)
#define DDERR_LOCKEDSURFACES MAKE_DDHRESULT(160)
#define DDERR_NO3D MAKE_DDHRESULT(170)
#define DDERR_NOALPHAHW MAKE_DDHRESULT(180)
#define DDERR_NOBLTHW MAKE_DDHRESULT(575)
#define DDERR_NOCLIPLIST MAKE_DDHRESULT(205)
#define DDERR_NOCLIPPERATTACHED MAKE_DDHRESULT(568)
#define DDERR_NOCOLORCONVHW MAKE_DDHRESULT(210)
#define DDERR_NOCOLORKEYHW MAKE_DDHRESULT(220)
#define DDERR_NOCOLORKEY MAKE_DDHRESULT(215)
#define DDERR_NOCOOPERATIVELEVELSET MAKE_DDHRESULT(212)
#define DDERR_NODC MAKE_DDHRESULT(586)
#define DDERR_NODDROPSHW MAKE_DDHRESULT(576)
#define DDERR_NODIRECTDRAWHW MAKE_DDHRESULT(563)
#define DDERR_NOEMULATION MAKE_DDHRESULT(565)
#define DDERR_NOEXCLUSIVEMODE MAKE_DDHRESULT(225)
#define DDERR_NOFLIPHW MAKE_DDHRESULT(230)
#define DDERR_NOGDI MAKE_DDHRESULT(240)
#define DDERR_NOHWND MAKE_DDHRESULT(569)
#define DDERR_NOMIPMAPHW MAKE_DDHRESULT(591)
#define DDERR_NOMIRRORHW MAKE_DDHRESULT(250)
#define DDERR_NOOVERLAYDEST MAKE_DDHRESULT(578)
#define DDERR_NOOVERLAYHW MAKE_DDHRESULT(260)
#define DDERR_NOPALETTEATTACHED MAKE_DDHRESULT(572)
#define DDERR_NOPALETTEHW MAKE_DDHRESULT(573)
#define DDERR_NORASTEROPHW MAKE_DDHRESULT(280)
#define DDERR_NOROTATIONHW MAKE_DDHRESULT(290)
#define DDERR_NOSTRETCHHW MAKE_DDHRESULT(310)
#define DDERR_NOT4BITCOLORINDEX MAKE_DDHRESULT(317)
#define DDERR_NOT4BITCOLOR MAKE_DDHRESULT(316)
#define DDERR_NOT8BITCOLOR MAKE_DDHRESULT(320)
#define DDERR_NOTAOVERLAYSURFACE MAKE_DDHRESULT(580)
#define DDERR_NOTEXTUREHW MAKE_DDHRESULT(330)
#define DDERR_NOTFLIPPABLE MAKE_DDHRESULT(582)
#define DDERR_NOTFOUND MAKE_DDHRESULT(255)
#define DDERR_NOTLOCKED MAKE_DDHRESULT(584)
#define DDERR_NOTPAGELOCKED MAKE_DDHRESULT(680)
#define DDERR_NOTPALETTIZED MAKE_DDHRESULT(589)
#define DDERR_NOVSYNCHW MAKE_DDHRESULT(335)
#define DDERR_NOZBUFFERHW MAKE_DDHRESULT(340)
#define DDERR_NOZOVERLAYHW MAKE_DDHRESULT(350)
#define DDERR_OUTOFCAPS MAKE_DDHRESULT(360)
#define DDERR_OUTOFMEMORY 0x8007000E
#define DDERR_OUTOFVIDEOMEMORY MAKE_DDHRESULT(380)
#define DDERR_OVERLAYCANTCLIP MAKE_DDHRESULT(382)
#define DDERR_OVERLAYCOLORKEYONLYONEACTIVE MAKE_DDHRESULT(384)
#define DDERR_OVERLAYNOTVISIBLE MAKE_DDHRESULT(577)
#define DDERR_PALETTEBUSY MAKE_DDHRESULT(387)
#define DDERR_PRIMARYSURFACEALREADYEXISTS MAKE_DDHRESULT(564)
#define DDERR_REGIONTOOSMALL MAKE_DDHRESULT(566)
#define DDERR_SURFACEALREADYATTACHED MAKE_DDHRESULT(410)
#define DDERR_SURFACEALREADYDEPENDENT MAKE_DDHRESULT(420)
#define DDERR_SURFACEBUSY MAKE_DDHRESULT(430)
#define DDERR_SURFACEISOBSCURED MAKE_DDHRESULT(440)
#define DDERR_SURFACELOST MAKE_DDHRESULT(450)
#define DDERR_SURFACENOTATTACHED MAKE_DDHRESULT(460)
#define DDERR_TOOBIGHEIGHT MAKE_DDHRESULT(470)
#define DDERR_TOOBIGSIZE MAKE_DDHRESULT(480)
#define DDERR_TOOBIGWIDTH MAKE_DDHRESULT(490)
#define DDERR_UNSUPPORTED 0x80004001
#define DDERR_UNSUPPORTEDFORMAT MAKE_DDHRESULT(510)
#define DDERR_UNSUPPORTEDMASK MAKE_DDHRESULT(520)
#define DDERR_VERTICALBLANKINPROGRESS MAKE_DDHRESULT(537)
#define DDERR_WASSTILLDRAWING MAKE_DDHRESULT(540)
#define DDERR_WRONGMODE MAKE_DDHRESULT(587)
#define DDERR_XALIGN MAKE_DDHRESULT(560)
#define DD_OK S_OK

#define DDBLTFAST_WAIT 0x00000010

#define DDLOCK_WRITEONLY 0x00000020L
#define DDLOCK_WAIT 0x00000001L

#define DDPCAPS_ALLOW256 0x00000040l
#define DDPCAPS_8BIT 0x00000004l

#define PC_RESERVED 0x01
#define PC_NOCOLLAPSE 0x04

#define DDWAITVB_BLOCKBEGIN 0x00000001l
