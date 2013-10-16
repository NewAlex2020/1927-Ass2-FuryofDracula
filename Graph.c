#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "HunterView.h"
#include "Graph.h"
#include "cities.h"
#include "connections.h"

typedef struct vNode *VList;

struct vNode { 
    Location v;     //ALICANTE etc
    Transport type; //LAND, SEA, ANY
    VList next; 
};  

struct GraphRep { 
    int nV; // #vertices
    int nE[NUM_TRANSPORT]; //counter for number of edges of each type    
    VList connections[NUM_MAP_LOCATIONS]; // array of lists 
}; 

static int canReachInNRecurs(Graph g, Location start, Location end, Transport type, int n);

Graph newGraph() { 
    int i; 
    Graph g = malloc(sizeof(struct GraphRep));
    assert(g != NULL);
    g->nV = NUM_MAP_LOCATIONS;
    for (i = 0; i < g->nV; i++){ 
        g->connections[i] = NULL;  
    }
     
    g->nE[LAND] = 0;
    g->nE[SEA] = 0; 
    g->nE[RAIL] = 0;
    makeHunterMap(g);
    return g; 
} 

void destroyGraph(Graph g){
    int i;
    VList curr;
    VList next;
    assert(g != NULL);
    assert(g->connections != NULL);
  
    for (i = 0; i < g->nV; i++){         
         curr = g->connections[i];
         while(curr !=NULL){
             next = curr->next;
             free(curr);
             curr=next;
         }
    }
    free(g);
}   


void addLink(Graph g, Location start, Location end, Transport type){
    VList endNode = malloc(sizeof(struct vNode));
    endNode->v = end;
    endNode->type = type;
    endNode->next = NULL;
    if (g->connections[start] == NULL) {
        g->connections[start] = endNode;
    } else {
        VList nextNode = g->connections[start];
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
        }
        nextNode->next = endNode;
    }

    VList startNode = malloc(sizeof(struct vNode));
    startNode->v = start;
    startNode->type = type;
    startNode->next = NULL;
    if (g->connections[end] == NULL) {
        g->connections[end] = startNode;
    } else {
        VList nextNode = g->connections[end];
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
        }
        nextNode->next = startNode;
    }

    g->nE[type]++;
}

//Useful for debugging
void showGraph(Graph g) { 
    assert(g != NULL); 
    printf("V=%d, E=%d + %d\n", g->nV, g->nE[LAND],g->nE[SEA]); 
    int i; 
    for (i = 0; i < g->nV; i++) { 
        VList n = g->connections[i]; 
        while (n != NULL) { 
            printf("%d-%d ",i,n->v); 
            if(n->type == LAND){
                printf("L ");
            } else if(n->type == SEA){
                printf("S ");
            } else {
                printf("ERROR NO SUCH TYPE");
                exit(0);
            }
            n = n->next; 
        } 
        if (g->connections [i] != NULL) 
            printf("\n"); 
        } 
} 

int numV(Graph g){
    assert(g != NULL);
    return g->nV;
}

int numE(Graph g, Transport type){
    assert(g != NULL);
    assert(type >= 0 && type <= ANY);
    if(type == ANY){
        return g->nE[LAND] + g->nE[SEA];
    } else {
        return g->nE[type];
    }
}

//returns 1 if there is an edge from start to end of the given type
//gives 0 otherwise
int isAdjacent(Graph g,Location start, Location end, Transport type){
    VList nextNode = g->connections[start];
    if (nextNode == NULL) {
        return FALSE;
    }
    while (nextNode != NULL) {
        if (nextNode->v == end && (nextNode->type == type || type == ANY)) {
            return TRUE;
        }
        nextNode = nextNode->next;
    }
    return FALSE;
}


//Determines which locations can be reached from the start location
//in n hops or less with a given transport type
//If a location can be reached in n hops or less locs[location] is set to 1
//otherwise it is left as 0
void canReachInN(Graph g, Location start, Transport type, int n, int locs[]){
    int i;
    for (i=0; i<NUM_MAP_LOCATIONS; i++) {
        Location end = i;
        locs[end] = canReachInNRecurs(g, start, end, type, n);
    }
}

int canReachInNRecurs(Graph g, Location start, Location end, Transport type, int n){
    VList nextNode = g->connections[start];
    
    if (nextNode == NULL) {
        return FALSE;
    }

    if (n == 0) {
        return (start == end);
    }

    if (start == end) {
        return TRUE;
    }


    nextNode = g->connections[start];
    
    while (nextNode != NULL) {
        if (type == ANY) {
            if (nextNode->v != start) {
                if (canReachInNRecurs(g, nextNode->v, end, type, n-1)) {
                    return TRUE;
                }
            }
        } else {
            if (nextNode->v != start && nextNode->type == type) {
                if (canReachInNRecurs(g, nextNode->v, end, type, n-1)) {
                    return TRUE;
                }
            }
        }
        nextNode = nextNode->next;
    }
    return FALSE;
}
