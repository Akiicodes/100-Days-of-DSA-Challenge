/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void levelOrder(struct Node* root){
    if(root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear){
        struct Node* curr = queue[front++];

        printf("%d ", curr->data);

        if(curr->left) queue[rear++] = curr->left;
        if(curr->right) queue[rear++] = curr->right;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for(int i = 0; i < n; i++){
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(nodes[i] != NULL){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n) nodes[i]->left = nodes[left];
            if(right < n) nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    levelOrder(root);

    return 0;
}