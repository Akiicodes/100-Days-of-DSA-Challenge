/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/
//Solution:
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int inStack[1000];
    int outStack[1000];
    int topIn;
    int topOut;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->topIn = -1;
    obj->topOut = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->inStack[++obj->topIn] = x;
}

void move(MyQueue* obj) {
    if(obj->topOut == -1) {
        while(obj->topIn != -1) {
            obj->outStack[++obj->topOut] = obj->inStack[obj->topIn--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    move(obj);
    return obj->outStack[obj->topOut--];
}

int myQueuePeek(MyQueue* obj) {
    move(obj);
    return obj->outStack[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->topIn == -1 && obj->topOut == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}