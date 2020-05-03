#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define GET_MIN(x, y) ((x) > (y)) ? (y) : (x)
int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int smallestDifference(int* a, int aSize, int* b, int bSize)
{
    int minDis = 0x7fffffff;
    int iA = 0, iB = 0;
    qsort(a, aSize, sizeof(int), MyCmp);
    qsort(b, bSize, sizeof(int), MyCmp);
    while (iA < aSize && iB < bSize) {
        minDis = GET_MIN(minDis, abs(a[iA] - b[iB]));
        if (a[iA] > b[iB]) {
            iB++;
        } else if (a[iA] < b[iB]){
            iA++;
        } else {
            minDis = 0;
            return minDis;
        }
    }
    return minDis;
}
int main()
{
    int a[] = {1, 3, 15, 11, 2};
    int b[] = {23, 127, 235, 19, 8};
    int aSize = sizeof(a) / sizeof(a[0]);
    int bSize = sizeof(b) / sizeof(b[0]);
    int minDis = smallestDifference(a, aSize, b, bSize);
    printf("%ld minDis %d\n", LONG,minDis);
    return 0;
}
