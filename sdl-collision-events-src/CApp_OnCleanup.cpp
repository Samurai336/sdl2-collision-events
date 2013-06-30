//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnCleanup() {
	CArea::AreaControl.OnCleanup();

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }

    CEntity::EntityList.clear();

    SDL_DestroyRenderer(Surf_Display);
    SDL_Quit();
}

//==============================================================================
