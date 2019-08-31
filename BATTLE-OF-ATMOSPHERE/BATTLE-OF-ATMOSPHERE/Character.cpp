#include"../BATTLE-OF-ATMOSPHERE/Character.h"

VOID SPACEMAN::SpaceManRelease(CHAR_* char_)
{
	// 仮の地面の座標(890)
	if (char_->y >= 890)
	{
		m_jump_power = m_max_jump_power;
		char_->m_jump = NO_JUMP;
		char_->m_is_call = FALSE;
	}
	else
	{
		m_plus_spaceman_speed = 0.0F;
		char_->m_is_dash = FALSE;
	}
}

VOID SPACEMAN::SpaceManJumpSwitchChange(JUMP* jump)
{
	switch (*jump)
	{
	case NO_JUMP:
		*jump = ONE_JUMP;
		break;
	case ONE_JUMP:
		*jump = TWO_JUMP;
		break;
	}
}

VOID SPACEMAN::SpaceManSwitchJump(JUMP jump, CHAR_* char_)
{
	switch (jump)
	{
	case NO_JUMP:

		// ジャンプしていないとき（落下など）自身に重力をかけている
		char_->y += m_gravity;
		m_gravity += m_max_gravity;
		break;

	case ONE_JUMP:

		SpaceManJump(char_);
		m_plus_jump_power = 0.0F;

		break;

	case TWO_JUMP:

		if (char_->m_is_call == FALSE)
		{
			m_jump_power = m_max_jump_power;
			char_->m_is_call = TRUE;
		}

		SpaceManJump(char_);

		break;
	}
}

VOID SPACEMAN::SpaceManJump(CHAR_* char_)
{
	char_->y -= m_jump_power;
	m_jump_power -= m_gravity;
}

VOID SPACEMAN::SpaceManDash(CHAR_ char_)
{
	if (char_.m_is_dash == TRUE) {

		if ((directx.KeyState[DIK_D] == directx.ON && directx.KeyState[DIK_G] == directx.ON) || (directx.KeyState[DIK_A] == directx.ON && directx.KeyState[DIK_G] == directx.ON))
		{

			m_plus_spaceman_speed += m_plus_dash_power;
			m_plus_jump_power += m_plus_dash_power;

			if (m_plus_spaceman_speed >=m_max_plus_spaceman_power)
			{
				m_plus_spaceman_speed = m_max_plus_spaceman_power;
				m_plus_jump_power = m_max_plus_spaceman_power;
			}
		}
		else if (directx.KeyState[DIK_G] == directx.OFF)
		{
			m_plus_spaceman_speed = 0.0F;
			m_plus_jump_power = 0.0F;
		}
	}
}

VOID SPACEMAN::SpaceManMove(CHAR_* char_)
{
	SpaceManRelease(char_);

	if (directx.KeyState[DIK_D] == directx.ON)
	{
		char_->x += (m_spaceman_speed + m_plus_spaceman_speed);
	}
	else if (directx.KeyState[DIK_A] == directx.ON)
	{
		char_->x -= (m_spaceman_speed +m_plus_spaceman_speed);
	}

	SpaceManDash(*char_);

	if (directx.KeyState[DIK_W] == directx.PRESS)
	{
		m_gravity = m_max_gravity;
		m_jump_power = (m_jump_power + m_plus_jump_power);

		SpaceManJumpSwitchChange(&char_->m_jump);
	}

	if (directx.KeyState[DIK_S] == directx.ON)
	{
		char_->y += m_spaceman_speed;
		char_->m_is_dash = FALSE;
	}
	else if (directx.KeyState[DIK_S] == directx.OFF)
	{
		char_->m_is_dash = TRUE;
	}

	//SPACEMAN1P::SpaceManSwitchJump(SPACEMAN1P::m_jump);

}
