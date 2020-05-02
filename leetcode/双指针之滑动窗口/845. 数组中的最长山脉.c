#include<stdio.h>
#include<stdlib.h>
#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)
int longestMountain(int* A, int ASize)
{
    int left, right;
    int mid;
    int max = 0;
    int hasUp = 0;
    int hasDown = 0;
    if (ASize < 3) {
        return 0;
    }

    for (mid = 0; mid < ASize; mid++) {
        // урвС╠ъ╫Г
        left = mid;
        while (left > 0) {
            if (A[left] > A[left - 1]) {
                left--;
            } else {
                break;
            }
        }
        // урср╠ъ╫Г
        right = mid;
        while (right < ASize - 1) {
            if (A[right] > A[right + 1]) {
                right++;
            } else {
                break;
            }
        }
        if (right > left && A[mid] > A[left] && A[mid] < A[right]) {
            max = GET_MAX(max, right - left + 1);
        }
    }
    return max;
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9};
    int ASize = sizeof(A) / sizeof(A[0]);
    int maxLen = longestMountain(A, ASize);
    printf("%d\n", maxLen);
}
