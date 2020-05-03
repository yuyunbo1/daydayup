#include<stdio.h>
#include<stdlib.h>
int CalMod(int x, int n)
{
    int i;
    int flag = n;
    int sum = 1;
    while (flag != 0) {
        if (flag == n) {
            x = x * 1;
        } else {
            x *= x;
        }
        if (flag & 0x1 != 0) {
            sum *= x;
        }
        flag = flag >> 1;
    }
    sum += 7;
    return sum;
}
int DfsCalMod(int x, int n)
{
    int sum = 1;
    if (n == 0 || n == 1) {
        return x;
    }
    if (n & 0x1 == 0) {
        return sum * DfsCalMod(x, n / 2) * DfsCalMod(x, n / 2);
    } else {
        return sum * DfsCalMod(x, n / 2) * DfsCalMod(x, (n + 1) / 2);
    }
}
int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int threeSumMulti(int* A, int ASize, int target)
{
    int mod;
    int left, right, mid;
    int curSum = 0;
    unsigned long long resCount = 0;
    int i;
    int tmpLeft, tmpRight;
    int numLeft, numRight;
    if (ASize < 3) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), MyCmp);
    for (mid = 0; mid < ASize; mid++) {
        left = mid + 1;
        right = ASize - 1;
        if (A[mid] > target) {
            break;
        }

        while (left < right) {
            curSum = A[mid] + A[left] + A[right];
            if (curSum > target) {
                right--;
            } else if (curSum < target) {
                left++;
            } else {
                tmpLeft = left;
                tmpRight = right;
                /**需要计算有几个A[left]即A[right],本次的结果为(left - tmpLeft + 1) * (tmpRight - right + 1)*/
                while (left < right && A[left] == A[left + 1]) {
                    left++;
                }
                while (left < right && A[right] == A[right - 1]) {
                    right--;
                }
                if (A[tmpLeft] == A[tmpRight]) {
                    resCount += (tmpRight - tmpLeft + 1) * (tmpRight - tmpLeft) / 2;
                    break;
                } else {
                    resCount += (left - tmpLeft + 1) * (tmpRight - right + 1);
                }
                left++;
                right--;
            }
        }
    }
    mod = DfsCalMod(10, 9) + 7;
    return resCount % mod;

}
int main()
{
    int A[] = {1,1,2,2,3,3,4,4,5,5};
    int ASize = sizeof(A) / sizeof(A[0]);
    int target = 8;
    int ret = threeSumMulti(A, ASize, target);
    printf("%d\n", ret);
}
