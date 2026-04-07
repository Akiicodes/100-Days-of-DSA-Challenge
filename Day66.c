/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
//Solution:
#include <stdio.h>

int dfs(int node, int adj[][100], int visited[], int recStack[], int V) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack, V))
                    return 1;
            } else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int detectCycle(int V, int adj[][100]) {
    int visited[V], recStack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, V))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    int adj[100][100] = {0}; // Assuming maximum of 100 vertices; adjust as needed.

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // Directed edge from u to v
    }

    if (detectCycle(V, adj)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}