//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit()
{




	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("failed to initi\n");
		printf("SDL_Init failed: %s\n", SDL_GetError()); 
        	return false;

    	}


	 window = SDL_CreateWindow("2.0 Port Test",
                        SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED,
                        WWIDTH, WHEIGHT,
                        SDL_WINDOW_RESIZABLE );


	 Surf_Display = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE|SDL_RENDERER_PRESENTVSYNC );


	/*
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
	*/ 


	 
    if(CArea::AreaControl.OnLoad("assets/maps/1.area", Surf_Display ) == false) {

	printf("failed to Load Map"); 
    	return false;
    }
	

    //SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

    if(Player.OnLoad("./assets/yoshi.png", 64, 64, 8, Surf_Display) == false) {
	
	printf("failed to Load Yoshi"); 
    	return false;
    }

    if(Player2.OnLoad("./assets/yoshi.png", 64, 64, 8, Surf_Display) == false) {

	printf("failed to Load Yoshi"); 
    	return false;
    }

    Player2.X = 100;

    CEntity::EntityList.push_back(&Player);
    CEntity::EntityList.push_back(&Player2);

	CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);

    return true;
}

//==============================================================================
