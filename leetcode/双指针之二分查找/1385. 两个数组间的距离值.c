/**
暴力解法
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    int i ,j;
    int distance = 0;
    for (i = 0; i < arr1Size; i++) {
        for (j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                break;
            }
        }
        if (j == arr2Size) {
            distance++;
        }
    }
    return distance;
}*/
/** 因为d肯定是在[0,arr1size]内，故可以用二分搜索，寻找右边界值*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int IsOk(int source, int* arr2, int arr2Size, int d)
{
    int i;
    for (i = 0; i < arr2Size; i++) {
        if (abs(source - arr2[i]) <= d) {
            return 0;
        }
    }
    return 1;
}
int MyCmp(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
int FindNeiighborIndex(int target, int* arr2, int arr2Size)
{
    int left = 0;
    int right = arr2Size - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr2[mid] == target) {
            return mid;
        }
        if (arr2[mid] > target) {
            if (mid == 0) {
                return 0;
            } else if (arr2[mid - 1] <= target) {
                return mid - 1;
            } else {
                right = mid - 1;
            }
        } else {
            left = mid + 1;
        }
    }
    if (left >= arr2Size) {
        return arr2Size - 1;
    }
    return 0;
}
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    int i;
    int distance = 0;
    int index;
    int minDis = 0xffff;
    int sum = 0;
    int len1 ,len2;
    qsort(arr2, arr2Size, sizeof(int), MyCmp);
    for (i = 0; i < arr1Size; i++) {
        index = FindNeiighborIndex(arr1[i], arr2, arr2Size);
        if (index == 0 && arr2Size == 1) {
            sum += abs(arr1[i] - arr2[0]) > d ? 1 : 0;
            continue;
        }
        if (index == arr2Size - 1) {
            len1 = abs(arr1[i] - arr2[index]);
            len2 = abs(arr1[i] - arr2[index - 1]);
            minDis =  len2 >= len1 ? len1 : len2;
            sum += minDis > d ? 1 : 0;
            continue;
        }
        len1 = abs(arr1[i] - arr2[index]);
        len2 = abs(arr1[i] - arr2[index + 1]);
        minDis =  len2 >= len1 ? len1 : len2;
        sum += minDis > d ? 1 : 0;
    }
    return sum;
}
int main()
{
    int arr1[] = {
       2,1,100,3};
    int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {
       -5,-2,10,-3,7};
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    int d = 6;
    int ret = findTheDistanceValue(arr1, arr1Size, arr2, arr2Size, d);
    printf("ret = %d\n", ret);
    return 0;
}
