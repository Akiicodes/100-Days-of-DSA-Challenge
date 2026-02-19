/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
//Solution:
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = arr[left] + arr[right];
    int first = arr[left], second = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", first, second);

    return 0;
}
