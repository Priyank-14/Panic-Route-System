#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

/*
==========================================================
        MODIFIED DIJKSTRA ALGORITHM
==========================================================

Finds SAFEST path using risk-based cost instead
of shortest distance.

==========================================================
*/

void dijkstra(Graph* graph, int src, int dest, int weight);

#endif