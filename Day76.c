/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
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

    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    printf("%d", count);
    return 0;
}