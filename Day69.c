//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue./*
//Solution:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int v, w;
    struct Edge* next;
};

struct Edge* createEdge(int v, int w) {
    struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
    e->v = v;
    e->w = w;
    e->next = NULL;
    return e;
}

struct MinHeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode* arr;
};

void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if (r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

struct MinHeapNode extractMin(struct MinHeap* h) {
    struct MinHeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void insert(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].dist = dist;

    while (i && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Edge* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Edge* e1 = createEdge(v, w);
        e1->next = adj[u];
        adj[u] = e1;

        struct Edge* e2 = createEdge(u, w);
        e2->next = adj[v];
        adj[v] = e2;
    }

    int src;
    scanf("%d", &src);

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;
    heap.arr = (struct MinHeapNode*)malloc(V * V * sizeof(struct MinHeapNode));

    dist[src] = 0;
    insert(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = extractMin(&heap);
        int u = minNode.v;

        struct Edge* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insert(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

    return 0;
}

