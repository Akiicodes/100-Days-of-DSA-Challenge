/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
//Solution:
#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    int prefixSum[MAX * 2];
    int index[MAX * 2];

    for (int i = 0; i < MAX * 2; i++)
        index[i] = -1;

    int offset = MAX;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (index[sum + offset] != -1) {
            int len = i - index[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            index[sum + offset] = i;
        }
    }

    printf("%d", maxLen);
    return 0;
}