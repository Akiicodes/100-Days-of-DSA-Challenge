/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void dfs(struct Node* adj[], int visited[], int s) {
    visited[s] = 1;
    printf("%d ", s);

    struct Node* temp = adj[s];
    while (temp) {
        if (!visited[temp->vertex])
            dfs(adj, visited, temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(adj, visited, s);

    return 0;
}