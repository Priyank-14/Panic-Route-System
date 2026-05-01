#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*
    Create empty heap
*/
MinHeap* createMinHeap(int capacity) {

    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));

    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HeapNode*)malloc(capacity * sizeof(HeapNode));

    return heap;
}

/*
    Swap helper
*/
void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

/*
    Maintain heap (upward)
*/
void heapifyUp(MinHeap* heap, int i) {

    while (i > 0 && heap->array[i].cost < heap->array[(i - 1) / 2].cost) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/*
    Maintain heap (downward)
*/
void heapifyDown(MinHeap* heap, int i) {

    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < heap->size && heap->array[l].cost < heap->array[smallest].cost)
        smallest = l;

    if (r < heap->size && heap->array[r].cost < heap->array[smallest].cost)
        smallest = r;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapifyDown(heap, smallest);
    }
}

/*
    Insert new node
*/
void insert(MinHeap* heap, int vertex, int cost) {

    int i = heap->size++;

    heap->array[i].vertex = vertex;
    heap->array[i].cost = cost;

    heapifyUp(heap, i);
}

/*
    Extract minimum cost node
*/
HeapNode extractMin(MinHeap* heap) {

    HeapNode root = heap->array[0];

    heap->array[0] = heap->array[--heap->size];

    heapifyDown(heap, 0);

    return root;
}

/*
    Check if empty
*/
int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}