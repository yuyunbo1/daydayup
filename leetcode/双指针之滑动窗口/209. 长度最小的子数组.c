#include<stdio.h>
#include<stdlib.h>
#define GET_MIN(x, y) ((x) > (y)) ? (y) : (x)
int minSubArrayLen(int s, int* nums, int numsSize)
{
    int left = 0;
    int right = 0;
    int curSum = 0;
    int curLen;
    int min = 0x7fffffff;
    if (s == 0) {
        return 1;
    }
    if (numsSize == 0) {
        return 0;
    }
    for (right = 0; right < numsSize; right++) {
        curSum += nums[right];
    }
    if (curSum < s) {
        return 0;
    }
    curSum = 0;
    for (right = 0; right < numsSize; right++) {

        curSum += nums[right];
        while (curSum >= s) {
            /**更新结果*/
            curLen = right - left + 1;
            min = GET_MIN(min, curLen);
            curSum -= nums[left];
            left++;
        }
    }
    return min;
}
int main()
{
    int nums[] = {2,3,1,2,4,3};
    int s = 7;
    int ret = minSubArrayLen(s, nums, sizeof(nums) / sizeof(nums[0]));
    printf("ret = %d\n", ret);
    return 0;
}
