#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <d3d9.h>

#include "../BATTLE-OF-ATMOSPHERE/Main.h"
#include "../BATTLE-OF-ATMOSPHERE/DirectX.h"
#include "../BATTLE-OF-ATMOSPHERE/Draw.h"

#include "../BATTLE-OF-ATMOSPHERE/Character.h"
#include "../BATTLE-OF-ATMOSPHERE/Stage.h"
#include "../BATTLE-OF-ATMOSPHERE/Collision.h"

enum TEX 
{
	TITLE_BG,
	TITLE_UI,
	TITLE_LOGO,
	CHARCTER,
	GAME_STAGE,
	GAME_BG,
	HELP_BG,
	RESULT_BG,
	MAXTEX,
};

enum SCENE 
{
	TITLE_SCENE,
	HELP_SCENE,
	GAME_SCENE,
	EXIT_SCENE,
	RESULT_SCENE,
};


extern DIRECTX directx;

extern SCENE scene;

extern DRAW draw;

//extern SPACEMAN spaceman;
//
//extern STAGE stage;
//
//extern COLLISION collision;

//WinMain関数
INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdline, _In_ INT nCmdShow);

//ウィンドプロシージャの生成
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//window作成
HWND GenerateWindow(HWND* hWnd, HINSTANCE* hInstance, const TCHAR* API_NAME);

//メインループ
VOID Mainloop(MSG* msg);

#endif
