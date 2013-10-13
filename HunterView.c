#include <stdlib.h>
#include <assert.h>
#include "game.h"
#include "HunterView.h"
#include "Graph.h"

// our #includes
#include <string.h>
#include <ctype.h>

// our local #defines
#define TRUE     1
#define FALSE    0
#define LEN_PLAY 7
#define PLAYERS {'G', 'S', 'H', 'M', 'D'}
#define LOCATION_CODES {
    "AL", "AM", "AT", "BA", "BI", "BE", "BR", "BO", "BU", "BC",
    "BD", "CA", "CG", "CD", "CF", "CO", "CN", "DU", "ED", "FL",
    "FR", "GA", "GW", "GE", "GO", "GR", "HA", "JM", "KL", "LE",
    "LI", "LS", "LV", "LO", "MA", "MN", "MR", "MI", "MU", "NA",
    "NP", "NU", "PA", "PL", "PR", "RO", "SA", "SN", "SR", "SJ",
    "SO", "ST", "SW", "SZ", "TO", "VA", "VR", "VE", "VI", "ZA",
    "ZU",
    "NS", "EC", "IS", "AO", "BB", "MS", "TS", "IO", "AS", "BS"
}
#define TRAP_ENCOUNTER_CODE     'T'
#define IMMATURE_ENCOUNTER_CODE 'V'
#define DRACULA_ENCOUNTER_CODE  'D'
// last line [61-70] are seas, the rest [0-60] are cities

// our local static functions
static void makePlaysArray(char *pastPlays, int n, char *array[LEN_PLAY+1]);
static int playerIndex(char letter);
static int locationIndex(char string[2]);
     
struct hunterView {
    // OH GOD WE NEED TO WRITE THIS OH GOD, WE DON'T HAVE MUCH TIME.
    // Stuff it'll need.
    Graph *board; // Board representation.
    int currentTurn;
    int score;   
    int roundNum;
    // ===== We can do these three in the newHunterView func at creation
    // . Or jsut store the history String
    // ===== and do it when the respective functions are called. Depends
    //  on what seems easier.
    // ===== We're gonna be parsing the history string to get score, cur
    // rentTurn and round anyway. Could
    // ===== be easier to also extract the info below and store it.
    // - array of player healths (inc. Drac). (Maybe be easier to do in 
    // the function getHealth, may not be.)
    // - array of player locations (inc. Drac).
    // - array of array's of player past 6 turn trails (inc. Drac)

    // ** If we're doing everything iteratively, perhaps:
    int health[NUM_PLAYERS]; // initialise appropriately
    // some loop for parsing, assume i is the looping variable

    // The data format for player plays is actually retarded, have to
    // account for different events not being there, oh well.
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
    hunterView->hello = 42;
    return hunterView;

    // ** How's the parsing being done? Will we just shove each
    // ** 'play' string into an array of strings? Such as:
    // char playStrings[SOME_CONSTANT][8];
    // char *playStrings[8] = malloc()

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
    // random code found on the internet for 2d array
    char ** playsArray;
    playsArray = (char **) malloc(numPlays * sizeof(char *));
    for (i = 0; i < numPlays; i++) {
        playsArray[i] = (char *) malloc((LEN_PLAY + 1) * sizeof(char));
    }
    makePlaysArray(pastPlays, numPlays, playsArray);


    // BEGIN THE GREAT LOOP OF PROCESSING SHIT.
    // before the game starts, initiate health
    char currentPlay[LEN_PLAY + 1];
    for (i = 0; i < NUM_PLAYERS - 1; i++) {
        hunterView->health[i] = GAME_START_HUNTER_LIFE_POINTS;
    }
    hunterView->health[PLAYER_DRACULA] = GAME_START_BLOOD_POINTS;

    int currTurn;
    int diedThisTurn = FALSE;
    PlayerID currPlayer;
    for (currTurn = 0; currTurn < numPlays; currTurn++) {
        strcpy (currentPlay, playsArray[currTurn]);
        currPlayer = playerIndex(currentPlay[0]);
        int strIndex = 3; // start of the actions
        // each turn consists of moving location, then doing an action

        // now to process the actions
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
            if (hunterView->health[currPlayer] <= 0) {
                diedThisTurn = TRUE;
                hunterView->health[currPlayer] == 0;
                // TODO - location becomes the hospital
            }
            strIndex++;
        }
    }


    // free random shit
    for (i = 0; i < numPlays; i++) {
        free(playsArray[i]);
    }
    free(playsArray);
}
     
     
// this function frees all memory previously allocated for the    
// HunterView
// toBeDeleted. toBeDeleted should not be accessed after the call.
void disposeHunterView( HunterView toBeDeleted ) {
    //COMPLETE THIS IMPLEMENTATION
    free( toBeDeleted );
}


//Functions to return simple information about the current state of 
// the game

//Get the current round
Round getRound (HunterView currentView) {


}

//Get the id of current player - ie whose turn is it?
// Only returns a 'playerID' which is one of:
//   LORD_GODALMING (0): Lord Godalming's turn
//   DR_SEWARD      (1): Dr. Seward's turn
//   VAN_HELSING    (2): Van Helsing's turn
//   MINA_HARKER    (3): Mina Harker's turn
//   DRACULA        (4): Dracula's turn
PlayerID getCurrentPlayer (HunterView currentView) {


}

//Get the current score
// Returns a positive integer [0...366]
int getScore(HunterView currentView) { 
    // game starts at 366
    // dracula finishes a turn => -1 == - SCORE_LOSS_DRACULA_TURN
    // hunter teleported to hospital => -6 == - SCORE_LOSS_HUNTER_HOSPITAL
    // vampire matures (dracula's 'V' action)
    //     => -13 == - SCORE_LOSS_VAMPIRE_MATURES
}

//Get the current health points for a given player
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


}   

//Functions that return information about the history of the game

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


}

//Functions that query the map to find information about connectivit

// y

//This function returns an array of LocationID that represent all lo

// cations that are connected 
//to the given LocationID. 
//road, rail and sea are connections should only be considered if th 
// e road, rail, sea parameters 
//are TRUE.
//The size of the array should be stored in the variable pointed to 
// by numLocations
//The array can be in any order but must contain unique entries
//Your function must take into account the round and player id for r
// ail travel
//Your function must take into account that dracula can't move to th
// e hospital or travel by rail
//but need not take into account draculas trail
//The destination 'from' should be included.
LocationID * connectedLocations(HunterView currentView, int * numLocations, LocationID from, 
                              PlayerID player, Round round, int road, int rail, int sea) {


}

static void makePlaysArray(char *pastPlays, int n, char *array[8]) {
    // n is the number of plays in the string
    int i;
    for (i = 0; i < n; i++) {
        fscanf(pastPlays, "%s ", &array[i]);
    }
}

static int playerIndex(char letter) {
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        if (letter == PLAYERS[i]) {
            return i;
        }
    }
    assert("Well, crap son\n" == 42);
}

static int locationIndex(char *string) {
    int i;
    for (i = 0; i < NUM_MAP_LOCATIONS; i++) {
        if (strcmp(string, 2, LOCATION_CODES[i]) == 0) {
            return i;
        }
    }
    assert("Well, that ain't a recognisable string" == 42);
}