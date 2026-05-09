/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;

    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int idx = 0;

    result[idx++] = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i].start <= result[idx - 1].end) {

            if (arr[i].end > result[idx - 1].end)
                result[idx - 1].end = arr[i].end;

        } else {

            result[idx++] = arr[i];
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}