/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int v;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = NULL;
    return node;
}

void dfs(struct Node* adj[], int visited[], int stack[], int* top, int node) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->v])
            dfs(adj, visited, stack, top, temp->v);
        temp = temp->next;
    }

    stack[(*top)++] = node;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int stack[V], top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(adj, visited, stack, &top, i);
    }

    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);

    return 0;
}