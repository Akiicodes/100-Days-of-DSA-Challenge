/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
//Solution:
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

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->v])
            dfs(temp->v, adj, visited);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node* n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    dfs(1, adj, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}