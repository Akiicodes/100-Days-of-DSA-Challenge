/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
//Solution:
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair* arr, int left, int mid, int right, int* count) {

    int n = right - left + 1;

    Pair* temp = (Pair*)malloc(n * sizeof(Pair));

    int i = left;
    int j = mid + 1;
    int k = 0;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[j].value < arr[i].value) {

            rightCount++;
            temp[k++] = arr[j++];

        } else {

            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {

        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(Pair* arr, int left, int right, int* count) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);

    merge(arr, left, mid, right, count);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int* result = (int*)calloc(numsSize, sizeof(int));

    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {

        arr[i].value = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, result);

    free(arr);

    return result;
}