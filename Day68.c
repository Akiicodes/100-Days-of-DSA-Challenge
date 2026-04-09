/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
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

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    int indegree[V];
    for (int i = 0; i < V; i++)
        indegree[i] = 0;

    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int topo[V], index = 0;

    while (front < rear) {
        int node = queue[front++];
        topo[index++] = node;

        struct Node* temp = adj[node];
        while (temp) {
            indegree[temp->v]--;
            if (indegree[temp->v] == 0)
                queue[rear++] = temp->v;
            temp = temp->next;
        }
    }

    if (index != V) {
        printf("Cycle exists\n");
    } else {
        for (int i = 0; i < V; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}