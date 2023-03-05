#include "main.h"


void GameStateMainMenuLoad(void){
	AEGfxSetBackgroundColor(0.f, 0.f, 0.f);
}
void GameStateMainMenuInit(void){}
void GameStateMainMenuUpdate(void){
	if (AEInputCheckTriggered(AEVK_1)) {
		gGameStateNext = GS_LEVEL1;
	}
	if (AEInputCheckTriggered(AEVK_2)) {
		gGameStateNext = GS_LEVEL2;
	}
	if (AEInputCheckTriggered(AEVK_Q)) {
		gGameStateNext = GS_QUIT;
	}
}
void GameStateMainMenuDraw(void){
	s8* Title{ "Platformer" };
	s8* L1option{ "Press '1' for Level 1" };
	s8* L2option{ "Press '2' for Level 2" };
	s8* Quit{ "Press 'Q' to Quit" };
	f32 swidth, sheight;
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);	
	AEGfxGetPrintSize(FontID, L1option, 1.f, swidth, sheight);
	AEGfxPrint(FontID, Title,	 0.f - swidth / 2.f, 0.f + sheight * 8.f, 1.f, 1.f, 0.f, 0.6f);
	AEGfxPrint(FontID, L1option, 0.f - swidth / 2.f, 0.f + sheight * 4.f, 1.f, 1.f, 1.f, 1.f);
	AEGfxPrint(FontID, L2option, 0.f - swidth / 2.f, 0.f + sheight * 2.f, 1.f, 1.f, 1.f, 1.f);
	AEGfxPrint(FontID, Quit,	 0.f - swidth / 2.f, 0.f + sheight * 0.f, 1.f, 1.f, 1.f, 1.f);


}
void GameStateMainMenuFree(void){}
void GameStateMainMenuUnload(void){}
