//==============================================================================
#ifndef _CMAP_H_
    #define _CMAP_H_

#include <SDL2/SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

//==============================================================================
class CMap {
	public:
		SDL_Texture*			Surf_Tileset;

	private:
		std::vector<CTile>      TileList;

	public:
		CMap();

	public:
		bool OnLoad(char* File);

		void OnRender(SDL_Renderer* Surf_Display, int MapX, int MapY);

    public:
        CTile*	GetTile(int X, int Y);
};

//==============================================================================

#endif
