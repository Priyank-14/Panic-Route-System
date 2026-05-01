#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/*
==========================================================
                GRAPH IMPLEMENTATION
==========================================================
*/

/*
    Function: createEdge

    Purpose:
    --------
    Creates a new road (edge) between nodes
*/
Edge* createEdge(int dest, int distance, int danger) {

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));

    newEdge->dest = dest;
    newEdge->distance = distance;
    newEdge->danger = danger;
    newEdge->next = NULL;

    return newEdge;
}

/*
    Function: createGraph

    Purpose:
    --------
    Initializes graph with given number of locations
*/
Graph* createGraph(int vertices) {

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

/*
    Function: addEdge

    Purpose:
    --------
    Adds a road between two locations (undirected)
*/
void addEdge(Graph* graph, int src, int dest, int distance, int danger) {

    // Add src → dest
    Edge* newEdge = createEdge(dest, distance, danger);
    newEdge->next = graph->adjList[src];
    graph->adjList[src] = newEdge;

    // Add dest → src
    newEdge = createEdge(src, distance, danger);
    newEdge->next = graph->adjList[dest];
    graph->adjList[dest] = newEdge;
}

/*
    Function: printGraph

    Purpose:
    --------
    Displays full city map
*/
void printGraph(Graph* graph) {

    for (int i = 0; i < graph->numVertices; i++) {

        printf("\nLocation %d:", i);

        Edge* temp = graph->adjList[i];

        while (temp != NULL) {
            printf(" -> %d (Dist:%d, Danger:%d)",
                   temp->dest,
                   temp->distance,
                   temp->danger);

            temp = temp->next;
        }

        printf("\n");
    }
}