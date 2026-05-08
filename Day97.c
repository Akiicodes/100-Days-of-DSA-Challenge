/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    Meeting* m1 = (Meeting*)a;
    Meeting* m2 = (Meeting*)b;

    return m1->start - m2->start;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    heap[heapSize++] = meetings[0].end;

    int maxRooms = 1;

    for (int i = 1; i < n; i++) {

        if (meetings[i].start >= heap[0]) {
            heap[0] = meetings[i].end;
            heapifyDown(heap, heapSize, 0);
        } else {
            heap[heapSize] = meetings[i].end;
            heapifyUp(heap, heapSize);
            heapSize++;
        }

        if (heapSize > maxRooms)
            maxRooms = heapSize;
    }

    printf("%d\n", maxRooms);

    return 0;
}