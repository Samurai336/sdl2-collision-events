//==============================================================================
// Surface functions
//==============================================================================
#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//==============================================================================
class CSurface {
	public:
		CSurface();

	public:
		static SDL_Texture* OnLoad(char* File, SDL_Renderer* MainRender);

		static bool OnDraw(SDL_Renderer* Surf_Dest, SDL_Texture* Surf_Src, int X, int Y, double rotation = 0.0);

		static bool OnDraw(SDL_Renderer* Surf_Dest, SDL_Texture* Surf_Src, int X, int Y, int X2, int Y2, int W, int H, double rotation = 0.0);

		static bool Transparent(SDL_Texture* Surf_Dest, int R, int G, int B);
};

//==============================================================================

#endif
