#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "game.h"
#include "HunterView.h"
#include "Graph.h"

// our #includes
#include <string.h>
#include <ctype.h>

// our local #defines
#define LEN_PLAY 7
const char players[] = {'G', 'S', 'H', 'M', 'D'};
const char* locationCodes[] = { \
    "AL", "AM", "AT", "BA", "BI", "BE", "BR", "BO", "BU", "BC", \
    "BD", "CA", "CG", "CD", "CF", "CO", "CN", "DU", "ED", "FL", \
    "FR", "GA", "GW", "GE", "GO", "GR", "HA", "JM", "KL", "LE", \
    "LI", "LS", "LV", "LO", "MA", "MN", "MR", "MI", "MU", "NA", \
    "NP", "NU", "PA", "PL", "PR", "RO", "SA", "SN", "SR", "SJ", \
    "SO", "ST", "SW", "SZ", "TO", "VA", "VR", "VE", "VI", "ZA", \
    "ZU", \
    "NS", "EC", "IS", "AO", "BB", "MS", "TS", "IO", "AS", "BS", \
    "C?", "S?", "HI", "D1", "D2", "D3", "D4", "D5", "TP"        \
};
// penultimate line [61-70] are seas, the rest [0-60] are cities,
// last line [71-79] are other locations, UNKNOWN == -1
const char seaLocationCodes[] = { \
    NORTH_SEA, ENGLISH_CHANNEL, IRISH_SEA, ATLANTIC_OCEAN,        \
    BAY_OF_BISCAY, MEDITERRANEAN_SEA, TYRRHENIAN_SEA, IONIAN_SEA, \
    ADRIATIC_SEA, BLACK_SEA, SEA_UNKNOWN\
};
#define NUM_SEA_LOCATIONS 11 // now including SEA_UNKNOWN
#define TRAP_ENCOUNTER_CODE     'T'
#define IMMATURE_ENCOUNTER_CODE 'V'
#define DRACULA_ENCOUNTER_CODE  'D'
#define TRAP_PLACED_CODE     'T'
#define IMMATURE_PLACED_CODE 'V'
#define TRAP_LEAVES_CODE     'M'
#define VAMPIRE_MATURES_CODE 'V'


// our local static functions
void makePlaysArray(char *pastPlays, int n, char *array[LEN_PLAY+1]);
int playerIndex(char letter);
int locationIndex(char string[2]);
void pushCus(HunterView current, PlayerID player, LocationID location);
int isSeaLocation(LocationID location);
int playerIsDead(HunterView current, PlayerID player);
int scoreIsZero(HunterView current);
int draculaMeetsHunter(HunterView current);
// isSeaLocation mainly used to see if Dracula is at sea


struct hunterView {

    Graph board; // Board representation.

    int currentTurn; // from 0 to N - derive player and round from this
    int curr;
    int score;

    int locations[NUM_PLAYERS][TRAIL_SIZE];

    int health[NUM_PLAYERS]; 

};
     
// newHunterView creates a new hunter view to summarise the current 
     
// state of
// the game.
//
// pastPlays is a string of all the plays made in the game so far by
//  all
// players (including Dracula) from earliest to most recent.
//
//
// messages is an array containing a playerMessage for each play in 
// the game
// so far. It will have exactly the same number of elements as there
//  are plays
// in pastPlays. The message from the first play will be at index 0,
//  and so on.
// The contents of each playerMessage will be exactly as provided by
//  the player.
//
// The "playerMessage" type is defined in game.h.
// You are free to ignore messages if you wish.
HunterView newHunterView( char *pastPlays, playerMessage messages[] ) {
    HunterView hunterView = malloc( sizeof( struct hunterView ) );
    //return hunterView;
    hunterView->board = newGraph();
    // ** How's the parsing being done? Will we just shove each
    // ** 'play' string into an array of strings? Such as:
    // char playStrings[SOME_CONSTANT][8];
    // char *playStrings[8] = malloc()

    // counting how many plays are in the string.
    int numPlays = 0;
    int i = 0;
    char temp = pastPlays[i];
    while (temp != EOF && temp != '\0') {
        temp = pastPlays[i];
        if (temp == ' ') {
            numPlays++;
        }
        i++;
    }
    if (pastPlays[0] != '\0') {
        numPlays++;
    }

    // random code found on the internet for 2d array
    char ** playsArray;
    playsArray = (char **) malloc(numPlays * sizeof(char *));
    for (i = 0; i < numPlays; i++) {

        playsArray[i] = (char *) malloc((LEN_PLAY + 1) * sizeof(char));
    }
    makePlaysArray(pastPlays, numPlays, playsArray);


    // BEGIN THE GREAT LOOP OF PROCESSING SHIT.
    // before the game starts, initiate health
    for (i = 0; i < NUM_PLAYERS - 1; i++) {

        hunterView->health[i] = GAME_START_HUNTER_LIFE_POINTS;
    }
    hunterView->health[PLAYER_DRACULA] = GAME_START_BLOOD_POINTS;
    hunterView->score = GAME_START_SCORE;
    // initialise location to unknown location
    int k;
    for (i = 0; i < NUM_PLAYERS; i++) {
        for (k = 0; k < TRAIL_SIZE; k++) {

            pushCus(hunterView, i, UNKNOWN_LOCATION);
        }
    }

    char currentPlay[LEN_PLAY + 1];
    int currTurn; // DO NOT CONFUSE WITH currTurn from hunterView
    int gameIsOver = FALSE;
    PlayerID currPlayer;

    for (currTurn = 0; currTurn < numPlays && !gameIsOver; currTurn++) {
        strcpy (currentPlay, playsArray[currTurn]);
        currPlayer = playerIndex(currentPlay[0]);

        char locationString[3] = {currentPlay[1],currentPlay[2],'\0'}; 
        LocationID currLocation = locationIndex(locationString);


        pushCus(hunterView, currPlayer, currLocation);
        if (hunterView->health[currPlayer] == 0) {
            hunterView->health[currPlayer] = GAME_START_HUNTER_LIFE_POINTS;
        }
        // could be wrong: what if they die this turn?

        // each turn consists of moving location, then doing an action

        // now to process the actions
        if (currPlayer != PLAYER_DRACULA) {

            if (hunterView->locations[currPlayer][0] ==
                hunterView->locations[currPlayer][1]) {
            
                hunterView->health[currPlayer] += LIFE_GAIN_REST;
                if (hunterView->health[currPlayer] > GAME_START_HUNTER_LIFE_POINTS) {

                    hunterView->health[currPlayer] = GAME_START_HUNTER_LIFE_POINTS;
                }

            }

            int strIndex = 3; // start of the actions
            int diedThisTurn = FALSE;
            while (diedThisTurn == FALSE && strIndex < LEN_PLAY
                   && currentPlay[strIndex] != '.') {

                if (currentPlay[strIndex] == TRAP_ENCOUNTER_CODE) {
                    hunterView->health[currPlayer] -= LIFE_LOSS_TRAP_ENCOUNTER;

                } else if (currentPlay[strIndex] == IMMATURE_ENCOUNTER_CODE) {
                    // pass
                } else if (currentPlay[strIndex] == DRACULA_ENCOUNTER_CODE) {
                    // omemergerhd I touched Dracula
                    hunterView->health[currPlayer] -= LIFE_LOSS_DRACULA_ENCOUNTER;
                    hunterView->health[PLAYER_DRACULA] -= LIFE_LOSS_HUNTER_ENCOUNTER;
                }

                if (playerIsDead(hunterView, currPlayer)) {

                    diedThisTurn = TRUE;
                    hunterView->health[currPlayer] = 0;
                    hunterView->score -= SCORE_LOSS_HUNTER_HOSPITAL;
                } else {
                    // didn't die this turn
                }
                if (playerIsDead(hunterView, PLAYER_DRACULA)) {
                    // GAME OVER MATE
                    gameIsOver = TRUE;
                }
                strIndex++;
            }


            if (hunterView->health[currPlayer] > GAME_START_HUNTER_LIFE_POINTS) {

                hunterView->health[currPlayer] = GAME_START_HUNTER_LIFE_POINTS;
            }

        } else { // omegherd dracula's turn
            assert(currPlayer == PLAYER_DRACULA);
            assert(currLocation != ST_JOSEPH_AND_ST_MARYS);

            if (currentPlay[3] == TRAP_PLACED_CODE) {
                // nothing?
            }
            if (currentPlay[4] == IMMATURE_PLACED_CODE) {
                // nothing?
            }
            // action code for dracula
            if (currentPlay[5] == TRAP_LEAVES_CODE) {
                // nothing?
            } else if (currentPlay[5] == VAMPIRE_MATURES_CODE) {

                hunterView->score -= SCORE_LOSS_VAMPIRE_MATURES;

            } else {
                // nothing, currentPlay[5] == '.'
            }

            if (playerIsDead(hunterView, PLAYER_DRACULA)) {
                // you just won the game
                gameIsOver = TRUE;
            } else {
                
                // life goes on hunting
                // sea hp loss is processed post-action

                if (currLocation == CASTLE_DRACULA) {

                    hunterView->health[PLAYER_DRACULA] += LIFE_GAIN_CASTLE_DRACULA;

                } else if (currLocation == TELEPORT) {

                    hunterView->health[PLAYER_DRACULA] += LIFE_GAIN_CASTLE_DRACULA;

                } else if (currLocation == SEA_UNKNOWN ||
                           isSeaLocation(currLocation)) {

                    hunterView->health[PLAYER_DRACULA] -= LIFE_LOSS_SEA;

                    if (playerIsDead(hunterView, PLAYER_DRACULA)) {
                        // game over
                        gameIsOver = TRUE;
                    }

                    if (hunterView->health[PLAYER_DRACULA] <= 0) {

                        hunterView->score -= SCORE_LOSS_DRACULA_TURN;
                    }
                } else if (currLocation == DOUBLE_BACK_1) {
                    LocationID history[TRAIL_SIZE];
                    getHistory(hunterView, currPlayer, history);

                    if (isSeaLocation(history[1])) {

                        hunterView->health[PLAYER_DRACULA] -= LIFE_LOSS_SEA;
                    }
                }
            }
        }
    }


    hunterView->currentTurn = numPlays;


    // free random shit
    for (i = 0; i < numPlays; i++) {
        free(playsArray[i]);
    }
    free(playsArray);

    return hunterView;
}
     
     
// this function frees all memory previously allocated for the    
// HunterView
// toBeDeleted. toBeDeleted should not be accessed after the call.
void disposeHunterView( HunterView toBeDeleted ) {
    // COMPLETE THIS IMPLEMENTATION
    // free(toBeDeleted->)
    destroyGraph(toBeDeleted->board);
    free( toBeDeleted );
}


// Functions to return simple information about the current state of 
// the game

// Get the current round
Round getRound (HunterView currentView) {
    // return currentView->roundNum;
    return currentView->currentTurn / NUM_PLAYERS;
}

// Get the id of current player - ie whose turn is it?
// Only returns a 'playerID' which is one of:
//   LORD_GODALMING (0): Lord Godalming's turn
//   DR_SEWARD      (1): Dr. Seward's turn
//   VAN_HELSING    (2): Van Helsing's turn
//   MINA_HARKER    (3): Mina Harker's turn
//   DRACULA        (4): Dracula's turn
PlayerID getCurrentPlayer (HunterView currentView) {
    // return currentView->currentTurn;
    return currentView->currentTurn % NUM_PLAYERS;
}

// Get the current score
// Returns a positive integer [0...366]
int getScore(HunterView currentView) { 
    // game starts at 366
    // dracula finishes a turn => -1 == - SCORE_LOSS_DRACULA_TURN
    // hunter teleported to hospital => -6 == - SCORE_LOSS_HUNTER_HOSPITAL
    // vampire matures (dracula's 'V' action)
    //     => -13 == - SCORE_LOSS_VAMPIRE_MATURES
    return currentView->score;
}

// Get the current health points for a given player
// 'player' specifies which players's life/blood points to return
//    and must be a value in the interval [0...4] (see 'player' type
// )

int getHealth(HunterView currentView, PlayerID player) {
    // DRACULA:
    // dracula starts at 40 hp == GAME_START_BLOOD_POINTS
    // encounter hunter => -10hp ***** == LIFE_LOSS_HUNTER_ENCOUNTER
    // every turn Dracula is at sea => -2 HP == LIFE_LOSS_SEA
    // @ castle dracula at end of turn && not defeated => +10 hp
    //     == LIFE_GAIN_CASTLE_DRACULA
    // dracula's hp is NOT capped
    // HUNTERS:
    // start at 9hp == GAME_START_HUNTER_LIFE_POINTS
    // encounters trap => -2hp == LIFE_LOSS_TRAP_ENCOUNTER
    // encounters dracula => -4hp ***** == LIFE_LOSS_DRACULA_ENCOUNTER
    // end turn in same city as their previous turn => +3hp == LIFE_GAIN_REST
    // hp capped at 9hp
    // check *****, not sure if it depends on who enters the city
    if (getLocation(currentView, player) == ST_JOSEPH_AND_ST_MARYS) {
        return GAME_START_HUNTER_LIFE_POINTS;
    } else {
        return currentView->health[player];
    }

}

// Get the current location id of a given player
// May be UNKNOWN_LOCATION if the player has not had a turn yet
// (ie at the beginning of the game when the round is 0)
// otherwise for a hunter it should be an integer in the interval [0
// ..70] 
// The given roundNumber is >= 0 and <= the current round number
// 'whichHunter' specifies which hunter's location to return
//    and must be a value in the interval [0...3] (see 'player' type
// )
// Or for dracula it should 
// gets the location of Dracula at the start of a particular round
// Returns an integer:
//   in the interval [0...70] if Dracula was known to be in a city o
// r sea
//   CITY_UNKNOWN     if Dracula was in an unknown city
//   SEA_UNKNOWN      if Dracula was in an unknown sea
//   HIDE             if Dracula was known to have made a hide move
//   DOUBLE_BACK_N    where N is [0...5], if Dracula was known to 
// have 
//                    made a double back move N positions back in 
// the trail
//                    e.g. DOUBLE_BACK_1 is the last place place he 
// visited
//   TELEPORT         if Dracula apparated back to Castle Dracula
//   LOCATION_UNKNOWN if the round number is 0
LocationID getLocation(HunterView currentView, PlayerID player) {

    if (currentView->health[player] == 0) {
        return ST_JOSEPH_AND_ST_MARYS;
    } else {
        return currentView->locations[player][0];
    }
}   

// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns f

// or the given player
// For dracula this may include integers:
//   in the interval [0...70] if Dracula was known to be in a city o
// r sea
//   CITY_UNKNOWN     if Dracula was in an unknown city
//   SEA_UNKNOWN      if Dracula was in an unknown sea

//   HIDE             if Dracula was known to have made a hide move
//   DOUBLE_BACK_N    where N is [0...5], if Dracula was known to ha
// ve
//                    made a double back move N positions back in th
// e trail
//                    e.g. DOUBLE_BACK_1 is the last place place he 
// visited
//   TELEPORT         if Dracula apparated back to Castle Dracula


// For any player if the move does not exist yet (i.e, the start of 


// the game),
// the value should be UNKNOWN_LOCATION (-1)
// For example after 2 turns the array may have the contents
// {29, 182, -1, -1, -1, -1} 
// This would mean in the first move the player started on location  
// 182 
// then moved to the current location of 29
void getHistory (HunterView currentView, PlayerID player,LocationID trail[TRAIL_SIZE]) {
    int *locations = currentView->locations[player];

    int i;
    for (i=0; i<TRAIL_SIZE; i++) {

        trail[i] = locations[i];
    }
}

// Functions that query the map to find information about connectivit

// y

// This function returns an array of LocationID that represent all
// locations that are connected to the given LocationID. 
// road, rail and sea are connections should only be considered if
// the road, rail, sea parameters are TRUE.
// The size of the array should be stored in the variable pointed to 
// by numLocations
// The array can be in any order but must contain unique entries
// Your function must take into account the round and player id for r
// ail travel
// Your function must take into account that dracula can't move to th
// e hospital or travel by rail
// but need not take into account draculas trail
// The destination 'from' should be included.
LocationID * connectedLocations(HunterView currentView,
                                int * numLocations, LocationID from, 
                                PlayerID player, Round round, int road,
                                int rail, int sea) {
    
    int count = 1;

    LocationID * connected = malloc(sizeof(LocationID)*count);

    connected[0] = from;

    // May I present the Three Amigos:

    // Road!
    if (road) {
        int i;
        for (i=0; i<NUM_MAP_LOCATIONS; i++) {
            if (isAdjacent(currentView->board, from, i, LAND)) {
                connected[count] = i;
                count++;
                connected = realloc(connected, sizeof(LocationID)*count+1);
            }
        }
    }

    // Sea!
    if (sea) {
        int i;
        for (i=0; i<NUM_MAP_LOCATIONS; i++) {
            if (isAdjacent(currentView->board, from, i, SEA)) {
                connected[count] = i;
                count++;
                connected = realloc(connected, sizeof(LocationID)*count+1);
            }
        }
    }

    // Rail!
    if (rail) {
        if ((round + player) % 4 == 1) {
            // one city
            int i;
            for (i=0; i<NUM_MAP_LOCATIONS; i++) {
                if (isAdjacent(currentView->board, from, i, RAIL)) {
                    connected[count] = i;
                    count++;
                    connected = realloc(connected, sizeof(LocationID)*count+1);
                }
            }
        } else if ((round + player) % 4 == 2) {
            // two cities
            int i;
            for (i=0; i<NUM_MAP_LOCATIONS; i++) {
                if (isAdjacent(currentView->board, from, i, RAIL)) {
                    connected[count] = i;
                    count++;
                    connected = realloc(connected, sizeof(LocationID)*count+1);

                    int j;
                    for (j=0; j<NUM_MAP_LOCATIONS; j++) {
                        if (isAdjacent(currentView->board, i, j, RAIL)) {
                            connected[count] = j;
                            count++;
                            connected = realloc(connected, sizeof(LocationID)*count+1);
                        }
                    }
                }
            }
        } else if ((round + player) % 4 == 3) {
            // three cities
            int i;
            for (i=0; i<NUM_MAP_LOCATIONS; i++) {
                if (isAdjacent(currentView->board, from, i, RAIL)) {
                    connected[count] = i;
                    count++;
                    connected = realloc(connected, sizeof(LocationID)*count+1);
                    
                    int j;
                    for (j=0; j<NUM_MAP_LOCATIONS; j++) {
                        if (isAdjacent(currentView->board, i, j, RAIL)) {
                            connected[count] = j;
                            count++;
                            connected = realloc(connected, sizeof(LocationID)*count+1);
                            int k;
                            for (k=0; k<NUM_MAP_LOCATIONS; k++) {
                                if (isAdjacent(currentView->board, j, k, RAIL)) {
                                    connected[count] = k;
                                    count++;
                                    connected = realloc(connected, sizeof(LocationID)*count+1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    *numLocations = count;

    connected = realloc(connected, sizeof(LocationID)*count-1);

    return connected;
}

 void makePlaysArray(char *pastPlays, int n, char *array[LEN_PLAY+1]) {
    // n is the number of plays in the string
    int bytesNow;
    int bytesConsumed = 0;
    int i;
    for (i = 0; i < n; i++) {
        sscanf(pastPlays + bytesConsumed, "%s %n", array[i], &bytesNow);
        bytesConsumed += bytesNow;
    }
}

 int playerIndex(char letter) {
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        if (letter == players[i]) {
            return i;
        }
    }
    assert(1 == 2);
}

 int locationIndex(char *string) {
    int i;
    for (i = 0; i < NUM_LOCATIONS; i++) {
        // changed this from NUM_MAP_LOCATIONS
        if (strcmp(string, locationCodes[i]) == 0) {
            // modified this to be correct, we now assume that
            // string is exactly 2 characters + '\0'
            return i;
        }
    }
    return UNKNOWN_LOCATION; // could be useful
}

 void pushCus(HunterView current, PlayerID player, LocationID location) {
    int i;
    for (i = (TRAIL_SIZE - 1); i > 0; i--) {
        current->locations[player][i] = current->locations[player][i - 1];
    }
    current->locations[player][0] = location;

}

 int isSeaLocation (LocationID location) {
    // used for reducing vampire health
    int i;
    for (i = 0; i < NUM_SEA_LOCATIONS; i++) {
        if (location == seaLocationCodes[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

 int playerIsDead(HunterView current, PlayerID player) {
    if (current->health[player] <= 0) {
        return TRUE;
    }
    return FALSE;
}

 int scoreIsZero(HunterView current) {
    if (current->score <= 0) {
        return TRUE;
    }
    return FALSE;
}

 int draculaMeetsHunter(HunterView current) {
    int i;
    const int draculaLoc = current->locations[PLAYER_DRACULA][0];
    for (i = 0; i < NUM_PLAYERS - 1; i++) {
        if (current->locations[i][0] == draculaLoc) {
            return i;
        }
    }

    return FALSE;
}