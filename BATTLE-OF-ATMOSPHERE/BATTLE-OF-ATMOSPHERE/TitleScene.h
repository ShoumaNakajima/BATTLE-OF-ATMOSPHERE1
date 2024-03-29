﻿#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <Windows.h>

#include "Main.h"

class TITLE 
{
public:

	VOID Title_Scene();

	FLOAT m_title_ui_tu_start = 0.0f;
	FLOAT m_title_ui_tu_help = 0.0f;
	FLOAT m_title_ui_tu_exit = 0.0f;

	enum SCENE_PHASE 
	{
		LOAD,
		PROCESSING,
		RELEASES
	};

private:

	enum SelectUI_ID
	{
		title_ui_start,
		title_ui_help,
		title_ui_exit,
	};

	
	SelectUI_ID current_id;
	SCENE nextscene = GAME_SCENE;

	//プロトタイプ宣言
	VOID Loading();
	VOID Process();
	VOID Release();

};

#endif