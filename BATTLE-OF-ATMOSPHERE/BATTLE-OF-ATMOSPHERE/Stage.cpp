﻿#include "Stage.h"

#include "MapChip.h"

//DRAWMAP drawmap;
//DRAW draw;



VOID STAGE::InitStageBlock()
{
	for (int i = 0; i < 5; i++) {
		block[i].x = (6 + i) * BLOCK_SIZE;
		block[i].y = 4 * BLOCK_SIZE;
	}
	for (int i = 0; i < 11; i++) {
		block[i + 5].x = (3 + i) * BLOCK_SIZE;
		block[i + 5].y = 8 * BLOCK_SIZE;
	}
}


VOID STAGE::InitBlock()
{
	//ブロックの初期値
	for (INT i = 0; i < BLOCK_QUANTITY;i++)
	{
		block[i].x = -10000.f;//初期値適当
		block[i].y = -10000.f;//初期値適当
		block[i].tu = 0.0f;
		block[i].tv = 0.0f;
		block[i].width = BLOCK_SIZE;
		block[i].height = BLOCK_SIZE;
	}
	//クリエイトブロックの初期値
	for (INT i = 0;i < CREATE_BLOCK_QUANITITY;i++) 
	{
		create_block[i].x = -10000.f;//初期値適当
		create_block[i].y = -10000.f;//初期値適当
		create_block[i].tu = 96.f / 192.f;
		create_block[i].tv = 0.0f;
		create_block[i].width = BLOCK_SIZE;
		create_block[i].height = BLOCK_SIZE;
	}

	InitStageBlock();
}

VOID STAGE::MakeStage(BLOCK* block)
{
	if (block->y == WINDOW_HEIGHT) {
		block->x = (float)(rand() % (1920 - (int)(BLOCK_SIZE)));
		block->y = -BLOCK_SIZE;
	}
}


VOID STAGE::ScrollBlock(BLOCK* block)
{	
	block->y += SCROLL_SPEED_BLOCK;
}

VOID STAGE::FallBlock() 
{




}

VOID STAGE::DrawBlock(BLOCK block)
{
	draw.Draw(block.x,block.y,0xffffffff,block.tu,block.tv,block.width,block.height,96.f/192.f, 96.f/192.f,GAME_STAGE,0);
}

