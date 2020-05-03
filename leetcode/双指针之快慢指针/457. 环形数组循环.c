#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
/**
首先判断是否循环，肯定用快慢指针。
1.一个循环中的所有运动都必须沿着同一方向进行：可以通过a * b > 0来进行判断
2.循环长度 > 1 可以通过判断slow == next(nums, slow)来判断，如果为真则表名循环长度只有1
*/
// step为1表示next,step为2表示next->next
int NextNStep(int* nums, int numsSize, int cur, int step)
{
    int i;
    int tmpIndex = cur;
    if (tmpIndex < 0 || tmpIndex > numsSize) {
        return 0x7fffffff;
    }
    for (i = 0; i < step; i++) {
            tmpIndex = tmpIndex + nums[tmpIndex];
        if (tmpIndex < 0) {
            /** <0的话*/
            tmpIndex = numsSize + tmpIndex % numsSize;
        } else {
            tmpIndex = tmpIndex % numsSize;
        }
    }
    return tmpIndex;
}
int circularArrayLoop(int* nums, int numsSize)
{
    int slow = 0;
    int fast = 0;
    int i;
    if (numsSize < 3) {
        return false;
    }
    for (i = 0; i < numsSize; i++) {
        /**初始化快慢指针，相当于slow = head,fast = head*/
        slow = i;
        fast = i;
        /**保持同方向，不同方向说明这个初始化位值不对*/
        while (nums[NextNStep(nums, numsSize, slow, 1)] * nums[i] > 0 &&
               nums[NextNStep(nums, numsSize, fast, 1)] * nums[i] > 0 &&
               nums[NextNStep(nums, numsSize, fast, 2)] * nums[i] > 0) {
            /**相当于slow = head->next fast = fast->next->next*/
            slow = NextNStep(nums, numsSize, slow, 1);
            fast = NextNStep(nums, numsSize, fast, 2);

            if (slow == fast) {
                /** 相等的话表明循环的长度只有1,表示这个起点肯定没有环*/
                if (slow == NextNStep(nums, numsSize, slow , 1)) {
                    break;
                }
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int nums[] = {-1};/** size = 7,*/
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = circularArrayLoop(nums, numsSize);
    printf("cur %d next is %d\n",0, NextNStep(nums, numsSize, 0, 1));
    printf("ret %d\n", ret);
}
