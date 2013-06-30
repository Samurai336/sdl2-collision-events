//==============================================================================
// SDL Tutorial 8
//==============================================================================
#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>

#include "Define.h"

#include "CFPS.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"

#include "CPlayer.h"

//==============================================================================
class CApp : public CEvent {
    private:
        bool            Running;

        SDL_Renderer*    Surf_Display;
		SDL_Window*		window;

        CPlayer			Player;
        CPlayer			Player2;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event* Event);

        	void OnKeyDown(SDL_Keycode sym,  SDL_Keymod mod, Uint16 unicode);

        	void OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode);

            void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

//==============================================================================

#endif
