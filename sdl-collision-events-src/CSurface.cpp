//==============================================================================
#include "CSurface.h"

//==============================================================================
CSurface::CSurface() {
}

//==============================================================================
SDL_Texture* CSurface::OnLoad(char* File , SDL_Renderer* MainRender ) {
	SDL_Surface* Surf_Temp = NULL;
	SDL_Texture* Surf_Return = NULL;

	if((Surf_Temp = IMG_Load(File)) == NULL) {
		return NULL;
	}

	Surf_Return = SDL_CreateTextureFromSurface( MainRender, Surf_Temp);
	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

//==============================================================================
bool CSurface::OnDraw(SDL_Renderer* Surf_Dest, SDL_Texture* Surf_Src, int X, int Y, double rotation) {
	if(Surf_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;


	SDL_RenderCopy(Surf_Dest, Surf_Src, NULL,&DestR); 

	SDL_RenderCopyEx(Surf_Dest, Surf_Src, NULL, &DestR, rotation, NULL, SDL_FLIP_NONE); 

	//SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}

//------------------------------------------------------------------------------
bool CSurface::OnDraw(SDL_Renderer* Surf_Dest, SDL_Texture* Surf_Src, int X, int Y, int X2, int Y2, int W, int H, double rotation ) {
	if(Surf_Dest == NULL || Surf_Src == NULL) {
		return false;
	}

	SDL_Rect DestR;

	DestR.x = X;
	DestR.y = Y;
	DestR.w = W;
	DestR.h = H;

	SDL_Rect SrcR;

	SrcR.x = X2;
	SrcR.y = Y2;
	SrcR.w = W;
	SrcR.h = H;

	//SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

		//SDL_RenderCopy(Surf_Dest,Surf_Src,  &SrcR, &DestR ); 

	SDL_RenderCopyEx(Surf_Dest, Surf_Src, &SrcR, &DestR, rotation, NULL, SDL_FLIP_NONE); 



	return true;
}

//------------------------------------------------------------------------------
bool CSurface::Transparent(SDL_Texture* Surf_Dest, int R, int G, int B) {
	if(Surf_Dest == NULL) {
		return false;
	}

		//SDL_SetTextureAlphaMod(Surf_Dest,  R, G, B);

	return true;
}

//==============================================================================
