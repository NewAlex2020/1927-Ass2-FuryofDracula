/* No time, not sure what that second test wil ldo lol.
*/


#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "cities.h"
#include "game.h"
#include "HunterView.h"


int main(int argc, char * argv[]) {
	playerMessage messages[] = {};
	
	printf("Test basic empty initialisation\n");
	HunterView hv = newHunterView("G", messages);
	assert(getCurrentPlayer(hv) == PLAYER_LORD_GODALMING);
	assert(getRound(hv) == 0);
	assert(getHealth(hv, PLAYER_DR_SEWARD) == GAME_START_HUNTER_LIFE_POINTS);
	assert(getHealth(hv, PLAYER_DRACULA) == GAME_START_BLOOD_POINTS);
        assert(getScore(hv) == GAME_START_SCORE);
        assert(getLocation(hv,PLAYER_LORD_GODALMING) == UNKNOWN_LOCATION);
        
	disposeHunterView(hv);
	printf("passed\n");

		printf("Test for Dracula trail and basic functions\n");
	hv = newHunterView("GGE.... SLV.... HZU.... MBB.... DJM....", messages2);
	assert(getCurrentPlayer(hv) == PLAYER_LORD_GODALMING);
	assert(getRound(hv) == 1);
	assert(getLocation(hv, PLAYER_LORD_GODALMING) == GENEVA);
	assert(getLocation(hv, PLAYER_DR_SEWARD) == LIVERPOOL);
	assert(getLocation(hv, PLAYER_VAN_HELSING) == ZURICH);
	assert(getLocation(hv, PLAYER_MINA_HARKER) == BAY_OF_BISCAY);
        assert(getLocation(hv, PLAYER_DRACULA) == ST_JOSEPH_AND_ST_MARYS);
	assert(getHealth(hv,PLAYER_DRACULA) == GAME_START_BLOOD_POINTS);
	printf("passed\n");
        disposeHunterView(hv);

	return 0;
}

