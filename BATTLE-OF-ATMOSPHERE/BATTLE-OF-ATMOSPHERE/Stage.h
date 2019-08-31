#ifndef STAGE_H_
#define STAGE_H_

#include <Windows.h>

//ブロックの大きさ
#define BLOCK_SIZE 100.f
//ブロックの個数
#define BLOCK_QUANTITY 100
//スクロールのスピード
#define SCROLL_SPEED  -0.001f
//ブロックのスクロールするスピード
#define SCROLL_SPEED_BLOCK 1.0f

typedef struct  {
	float x, y, width, height, tu, tv;
}BLOCK;

class STAGE {
public:





	VOID InitStage();

	VOID MakeStage();

	VOID ScrollBlock(BLOCK* block);

	VOID FallBlock();

	VOID DrawBlock(BLOCK block);
	
	BLOCK block[BLOCK_QUANTITY];



};

#endif
