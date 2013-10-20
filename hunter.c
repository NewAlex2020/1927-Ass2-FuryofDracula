#include "game.h"
#include "HunterView.h"
#include "hunter.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// #include "cities.h"
#include "Graph.h" // to go to random adjacent location

static char* locationCodes[] = { \
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

void decideMove (HunterView gameState) {

    // registerBestPlay("ZU", "I Wanna Stake You Dracula <3" );
    const PlayerID currPlayer = getCurrentPlayer(gameState);
    const LocationID currLoc  = getLocation(gameState, currPlayer);
    if (getRound(gameState) == 0) {
        if (currPlayer == PLAYER_LORD_GODALMING) {
            registerBestPlay(locationCodes[GALWAY], "");
        } else if (currPlayer == PLAYER_DR_SEWARD) {
            registerBestPlay(locationCodes[GALATZ], "");
        } else if (currPlayer == PLAYER_VAN_HELSING) {
            registerBestPlay(locationCodes[ATHENS], "");
        } else if (currPlayer == PLAYER_MINA_HARKER) {
            registerBestPlay(locationCodes[MADRID], "");
        } else {
            assert ("This isn't Dracula's turn m8 uwot\n");
        }
        return; // doesn't run the next batch of code
    }
    // not the first turn of the game eh
    if (currPlayer == PLAYER_LORD_GODALMING) {
        registerBestPlay(locationCodes[currLoc], "I'm so lazy");
    } else if (currPlayer == PLAYER_DR_SEWARD) {
        if (currLoc == GALATZ) {
            registerBestPlay(locationCodes[KLAUSENBURG], "switcheroo");
        } else if (currLoc == KLAUSENBURG) {
            registerBestPlay(locationCodes[GALATZ], "rooerswitch");
        } else {
            registerBestPlay(locationCodes[currLoc], "screw switching, too hard");
        }
    } else if (currPlayer == PLAYER_VAN_HELSING) {
        // pick a random city by land
        int * numLocations = malloc(sizeof(int));
        LocationID * options = connectedLocations(gameState, numLocations, getLocation(gameState, currPlayer), currPlayer, getRound(gameState), 1, 0, 0);
        int randIndex = rand()/RAND_MAX * (*numLocations);
        free(numLocations);
        registerBestPlay(locationCodes[options[randIndex]], "who knows where I'll be");
    } else if (currPlayer == PLAYER_MINA_HARKER) {
        // pick a random city by land or sea
        int * numLocations = malloc(sizeof(int));
        LocationID * options = connectedLocations(gameState, numLocations, getLocation(gameState, currPlayer), currPlayer, getRound(gameState), 1, 1, 0);
        int randIndex = rand()/RAND_MAX * (*numLocations);
        free(numLocations);
        registerBestPlay(locationCodes[options[randIndex]], "who knows where I'll be");
    } else {
        assert ("This isn't Dracula's turn m8 uwot\n");
    }
}

