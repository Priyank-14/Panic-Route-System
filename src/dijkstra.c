#include <stdio.h>
#include <limits.h>
#include "dijkstra.h"
#include "heap.h"
#include "risk.h"

/*
    Print path recursively
*/
void printPath(int parent[], int j) {
    if (j == -1) return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

/*
    Modified Dijkstra Algorithm
*/
void dijkstra(Graph* graph, int src, int dest, int weight) {

    int n = graph->numVertices;

    int dist[n];
    int visited[n];
    int parent[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    MinHeap* heap = createMinHeap(n);

    dist[src] = 0;
    insert(heap, src, 0);

    while (!isEmpty(heap)) {

        int u = extractMin(heap).vertex;

        if (visited[u]) continue;

        visited[u] = 1;

        Edge* temp = graph->adjList[u];

        while (temp) {

            int v = temp->dest;

            int cost = calculateRiskCost(temp->distance,
                                         temp->danger,
                                         weight);

            if (!visited[v] && dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                parent[v] = u;
                insert(heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    if (dist[dest] == INT_MAX) {
        printf("\nNo safe path found.\n");
        return;
    }

    printf("\nSAFEST PATH: ");
    printPath(parent, dest);

    printf("\nTOTAL COST: %d\n", dist[dest]);
}