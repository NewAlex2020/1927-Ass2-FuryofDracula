#include <stdlib.h>
#include <assert.h>
#include "game.h"
#include "HunterView.h"
#include "Graph.h"
     
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
    int hello;
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

}

//Get the current health points for a given player
// 'player' specifies which players's life/blood points to return
//    and must be a value in the interval [0...4] (see 'player' type
// )

int getHealth(HunterView currentView, PlayerID player) {


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

