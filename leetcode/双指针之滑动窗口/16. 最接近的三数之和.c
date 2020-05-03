#include<stdio.h>
#include<stdlib.h>
int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int threeSumClosest(int* nums, int numsSize, int target)
{
    int left, right;
    int mid;
    int curSum;
    int ret;
    int tmpRet;
    int tmpDis = 0x7fffffff;
    int dis = 0x7fffffff;
    if (numsSize < 3) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), MyCmp);
    for (mid = 0; mid < numsSize; mid++) {
        if (mid > 0 && nums[mid] == nums[mid - 1]) {
            continue;
        }
        left = mid + 1;
        right = numsSize - 1;
        tmpDis = 0x7fffffff;
        while (left < right) {
            curSum = nums[mid] + nums[left] + nums[right];
            if (curSum < target) {
                left++;
            } else if (curSum > target) {
                right--;
            } else {
                return target;
            }
            if (abs(curSum - target) < tmpDis) {
                tmpDis = abs(curSum - target);
                tmpRet = curSum;
            }
        }
        if (abs(tmpRet - target) < dis) {
            dis = abs(tmpRet - target);
            ret = tmpRet;
        }
    }
    return ret;
}
int main()
{
    int nums[] = {1,2,5,10,11};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 12;
    int ret = threeSumClosest(nums, numsSize, target);
    printf("%d\n", ret);
}
