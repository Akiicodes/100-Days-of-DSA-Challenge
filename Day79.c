/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
//Solution:
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size;
    struct HeapNode* arr;
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
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

struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->arr[0];
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
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n+1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* n1 = createNode(v, w);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = createNode(u, w);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int src;
    scanf("%d", &src);

    int dist[n+1];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;
    heap.arr = (struct HeapNode*)malloc(100000 * sizeof(struct HeapNode));

    dist[src] = 0;
    insert(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode node = extractMin(&heap);
        int u = node.v;

        struct Node* temp = adj[u];
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

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}