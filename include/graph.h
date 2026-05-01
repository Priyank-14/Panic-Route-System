#ifndef GRAPH_H
#define GRAPH_H

/*
==========================================================
                    GRAPH MODULE
==========================================================

This module is responsible for:
- Representing the city map as a graph
- Storing roads with distance and danger levels
- Using adjacency list representation

==========================================================
*/

#define MAX 50   // Maximum number of locations

/*
    Structure: Edge

    Represents a road between two locations
*/
typedef struct Edge {
    int dest;          // Destination node
    int distance;      // Distance of road
    int danger;        // Danger level (0–10)
    struct Edge* next; // Pointer to next edge
} Edge;

/*
    Structure: Graph

    Stores adjacency list of all locations
*/
typedef struct Graph {
    int numVertices;     // Number of locations
    Edge* adjList[MAX];  // Array of linked lists
} Graph;

/* Function Declarations */

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest, int distance, int danger);
void printGraph(Graph* graph);

#endif