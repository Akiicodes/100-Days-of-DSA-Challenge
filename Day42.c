/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/
//Solution:
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x){
    queue[++rear] = x;
}

int dequeue(){
    return queue[front++];
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    while(front <= rear)
        push(dequeue());

    front = 0;
    rear = -1;

    while(top != -1)
        enqueue(pop());

    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}