/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct vertexTag {
    graphElementT element;
    int visited;
    struct edgeTag *edges;
    struct vertexTag *next;
} vertexT;

typedef struct edgeTag {
    struct vertexTag *connectsTo;
    struct edgeTag *next;
} edgeT;

typedef struct graphCDT {
    vertexT *vertices;
} graphCDT;

GraphAddVertex();
GraphAddEdge();


int GraphIsReachable(graphADT graph, graphElementT dest, graphElementT source) {
    vertexT *vertP;
    vertexT *startP = NULL;


   * Go through each vertex, mark them
   * as "not visited" and also record
   * where the start vertex is.


for (vertP = graph->vertices; vertP != NULL; vertP = vertP->next) {
    vertP->visited = 0;
    if (vertP->element == source){
        startP = vertP;
    }
}

  /* Make sure the starting point exists. */

  if (startP == NULL)
    return 0;

  /* Now see if we can get there from here. */

  return RecIsReachable(dest, startP);
}


GraphCreate();
GraphDestroy();
*/