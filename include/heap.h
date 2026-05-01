#ifndef HEAP_H
#define HEAP_H

/*
==========================================================
            MIN HEAP (PRIORITY QUEUE)
==========================================================

Used in Dijkstra algorithm to always pick
the node with minimum cost.

==========================================================
*/

typedef struct {
    int vertex;
    int cost;
} HeapNode;

typedef struct {
    int size;
    int capacity;
    HeapNode* array;
} MinHeap;

MinHeap* createMinHeap(int capacity);
void insert(MinHeap* heap, int vertex, int cost);
HeapNode extractMin(MinHeap* heap);
int isEmpty(MinHeap* heap);

#endif