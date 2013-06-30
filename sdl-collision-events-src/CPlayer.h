//=============================================================================
#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "CEntity.h"

//=============================================================================
class CPlayer : public CEntity {
    public:
        CPlayer();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames, SDL_Renderer* MainDispaly);

        void OnLoop();

        void OnRender(SDL_Renderer * Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);
};

//=============================================================================

#endif


