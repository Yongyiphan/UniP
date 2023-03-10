// ---------------------------------------------------------------------------
// includes

#include "AEEngine.h"



// ---------------------------------------------------------------------------
// main


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	int gGameRunning = 1;

	// Initialization of your own variables go here
	
	// Using custom window procedure
	AESysInit(hInstance, nCmdShow, 800, 600, 1, 60, true, NULL);

	// Changing the window title
	AESysSetWindowTitle("My New Demo!");

	// reset the system modules
	AESysReset();

	// Pointer to Mesh
	AEGfxVertexList * pMesh = 0;
	// Informing the library that we're about to start adding triangles
	AEGfxMeshStart();
	// This shape has 2 triangles that makes up a square
	// Color parameters represent colours as ARGB
	// UV coordinates to read from loaded textures
	AEGfxTriAdd(
     30.f, -30.f, 0x00FFFFFF, 1.f, 1.0f,
	-30.f, -30.f, 0x00FFFFFF, 0.0f, 1.0f,
	-30.f,  30.f, 0x00FFFFFF, 0.0f, 0.0f);
	AEGfxTriAdd(
	 30.f, -30.f, 0x00FFFFFF, 1.f, 1.0f,
	 30.f,  30.f, 0x00FFFFFF, 1.f, 0.0f,
	-30.f,  30.f, 0x00FFFFFF, 0.0f, 0.0f);
	// Saving the mesh (list of triangles) in pMesh
	pMesh = AEGfxMeshEnd();
	//AEGfxTexture* pTex = AEGfxTextureLoad("./Assets/PlanetTexture.png");
	AEGfxTexture* pTex = AEGfxTextureLoad("./Assets/SushiRiceBall.png");
	
	int rad = 0;

	// Game Loop
	while (gGameRunning)
	{
		// Informing the system about the loop's start
		AESysFrameStart();
		// Handling Input
		s32 x, y;
		AEInputGetCursorPosition(&x, &y);
		AEInputUpdate();
		// Your own update logic goes here
		if (AEInputCheckTriggered(AEVK_D)) {
			rad += 1.5;
		}
		if (AEInputCheckTriggered(AEVK_A)) {
			rad -= 0.5;
		}

		// Your own rendering logic goes here
		// Set the background to black.
		AEGfxSetBackgroundColor(1.0f, 1.0f, 1.0f);
		// Tell the engine to get ready to draw something with texture.
		AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
		// Set the tint to white, so that the sprite can 
		// display the full range of colors (default is black).
		AEGfxSetTintColor(1.0f, 1.0f, 1.0f, 1.0f);
		// Set blend mode to AE_GFX_BM_BLEND
		//AEGfxSetBlendMode(AE_GFX_BM_BLEND);
		// This will allow transparency.
		AEGfxSetTransparency(1.0f);
		// Set the texture to pTex
		AEGfxTextureSet(pTex, 0, 0);
		// Create a scale matrix that scales by 100 x and y
		AEMtx33 scale = { 0 };
		AEMtx33Scale(&scale, 5.f, 5.f);
		// Create a rotation matrix that rotates by 45 degrees
		AEMtx33 rotate = { 0 };
		//AEMtx33Rot(&rotate, PI/4);
		AEMtx33Rot(&rotate, rad);
		// Create a translation matrix that translates by
		// 100 in the x-axis and 100 in the y-axis
		//AEMtx33 translate = { 0 };
		//AEMtx33Trans(&translate, 100.f, 100.f);
		// Concat the matrices (TRS)
		AEMtx33 transform = { 0 };
		AEMtx33Concat(&transform, &rotate, &scale);
		//AEMtx33Concat(&transform, &translate, &transform);
		// Choose the transform to use
		AEGfxSetTransform(transform.m);
		// Actually drawing the mesh 
		AEGfxMeshDraw(pMesh, AE_GFX_MDM_TRIANGLES);

		// Informing the system about the loop's end
		AESysFrameEnd();

		// check if forcing the application to quit
		if (AEInputCheckTriggered(AEVK_ESCAPE) || 0 == AESysDoesWindowExist())
			gGameRunning = 0;
	}

	AEGfxMeshFree(pMesh);
	AEGfxTextureUnload(pTex);
	// free the system
	AESysExit();
}