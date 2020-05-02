#include<stdlib.h>
#include<stdio.h>
int numSubarraysWithSum(int* A, int ASize, int S)
{
    int left = 0;
    int right;
    int resNum = 0;
    int curSum = 0;
    int leftNum, rightNum;
    int tmp = 0;
    if (S > ASize || ASize == 0) {
        return 0;
    }
    if (S == 0) {
        for (right = 0; right < ASize; right = tmp) {
            if (A[right] != 0) {
                tmp++;
                continue;
            }
            left = right;
            for (tmp = right; tmp < ASize; tmp++) {
                if (A[tmp] != 0) {
                    break;
                }
                resNum += tmp - left + 1;
            }

        }
        return resNum;
    }
    for (right = 0; right < ASize; right++) {
        /**先找到窗口*/
        curSum += A[right];
        /**往右看看可以添加几个*/
        if (curSum == S) {
            rightNum = 0;
            for (tmp = right + 1; tmp < ASize; tmp++) {
                if (A[tmp] == 1) {
                    break;
                }
            }
            rightNum = tmp - right - 1;
        } else {
            continue;
        }

        tmp = left;
        while (curSum >= S) {
            curSum -= A[left];
            left++;
        }
        leftNum = left - tmp - 1;

        resNum += (leftNum + 1) * (rightNum + 1);
    }
    return resNum;
}
int main()
{
    int A[] = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
    int ASize = sizeof(A) / sizeof(A[0]);
    int resNum;
    int s = 3;
    resNum = numSubarraysWithSum(A, ASize, s);
    printf("%d\n", resNum);
}
