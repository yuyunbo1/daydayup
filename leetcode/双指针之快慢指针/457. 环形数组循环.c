#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
/**
�����ж��Ƿ�ѭ�����϶��ÿ���ָ�롣
1.һ��ѭ���е������˶�����������ͬһ������У�����ͨ��a * b > 0�������ж�
2.ѭ������ > 1 ����ͨ���ж�slow == next(nums, slow)���жϣ����Ϊ�������ѭ������ֻ��1
*/
// stepΪ1��ʾnext,stepΪ2��ʾnext->next
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
            /** <0�Ļ�*/
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
        /**��ʼ������ָ�룬�൱��slow = head,fast = head*/
        slow = i;
        fast = i;
        /**����ͬ���򣬲�ͬ����˵�������ʼ��λֵ����*/
        while (nums[NextNStep(nums, numsSize, slow, 1)] * nums[i] > 0 &&
               nums[NextNStep(nums, numsSize, fast, 1)] * nums[i] > 0 &&
               nums[NextNStep(nums, numsSize, fast, 2)] * nums[i] > 0) {
            /**�൱��slow = head->next fast = fast->next->next*/
            slow = NextNStep(nums, numsSize, slow, 1);
            fast = NextNStep(nums, numsSize, fast, 2);

            if (slow == fast) {
                /** ��ȵĻ�����ѭ���ĳ���ֻ��1,��ʾ������϶�û�л�*/
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
