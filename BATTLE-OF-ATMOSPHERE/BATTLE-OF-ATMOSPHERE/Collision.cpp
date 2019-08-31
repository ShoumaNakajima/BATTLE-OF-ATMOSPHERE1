#include "Collision.h"


SPACEMAN spaceman;

VOID COLLISION::Hit_Block(BLOCK block,CHAR_* char_,JUMP jump)
{
	if((block.x <= char_->x + char_->width) && (char_->x <= block.x + block.width) && (block.y <= char_->y + char_->height) && (char_->y <= block.y + block.height))
	{
		
		char_->is_hit_block = true;

	}

	if (char_->is_hit_block == false)
	{

		spaceman.SpaceManSwitchJump(jump,char_);
	
	}

}