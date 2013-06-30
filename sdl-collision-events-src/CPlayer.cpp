//=============================================================================
#include "CPlayer.h"

//=============================================================================
CPlayer::CPlayer() {
}

//=============================================================================
bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames, SDL_Renderer*  MainDispaly) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames, MainDispaly) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CPlayer::OnLoop()
{

	/* Rotation Test
	if(rotation >= 360)
	{
		rotation = 0;
	}
	else
	{

		rotation += 0.5;
	}
	*/

	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CPlayer::OnRender(SDL_Renderer* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CPlayer::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CPlayer::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CPlayer::OnCollision(CEntity* Entity)
{
    Jump();

    return true;

}

//=============================================================================
