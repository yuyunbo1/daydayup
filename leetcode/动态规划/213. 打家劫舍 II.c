
/**
 [1,2,3,1]
 其实找出n / 2个元素使得和最大
step是选取一个元素
option是这么有n个元素可以选择
*/
/**

*/
#include<stdio.h>
#include<stdlib.h>
int* memMax = NULL;
#if 0
int g_max = 0;
int* vis = NULL;

void PickOneRommDfs(int* nums, int num, int curStartIndex, int curSum)
{
    int i;
    if (g_max < curSum) {
        g_max = curSum;
    }
    if (curStartIndex >= num) {
        return;
    }
    /**不用for循环了因为只能从curStartIndex中选择，然后就是选或不选的问题*/
        /**选*/
    vis[curStartIndex] = 1;
    if (!(curStartIndex == num - 1 && vis[0] == 1)) {
        PickOneRommDfs(nums, num, curStartIndex + 2, curSum + nums[curStartIndex]);
    }
    vis[curStartIndex] = 0;
        /**不选*/
    PickOneRommDfs(nums, num, curStartIndex + 1, curSum);
}
int rob(int* nums, int numsSize)
{
    int i;
    g_max = 0;
    vis = (int*)calloc(numsSize, sizeof(int));
    if (numsSize == 1) {
        return nums[0];
    }
    PickOneRommDfs(nums, numsSize, 0, 0);
    free(vis);
    return g_max;
}
#endif

int PickOneRoomDfs(int* nums, int startIndex, int endSize)
{
    int doIt, notDoIt;
    int res;
    if (startIndex >= endSize) {
        return 0;
    }
    if (memMax[startIndex] != -1) {
        return memMax[startIndex];
    }
    notDoIt = PickOneRoomDfs(nums, startIndex + 1, endSize);
    doIt = PickOneRoomDfs(nums, startIndex + 2, endSize) + nums[startIndex];
    res = notDoIt > doIt ? notDoIt :  doIt;
    memMax[startIndex] = res;
    return res;
}

int rob(int* nums, int numsSize)
{
    int i;
    memMax = (int*)calloc(numsSize, sizeof(int));
    for (i = 0; i < numsSize; i++) {
        memMax[i] = -1;
    }
    int doFirst = PickOneRoomDfs(nums, 0, numsSize - 1);
    for (i = 0; i < numsSize; i++) {
        memMax[i] = -1;
    }
    int notDoFirst = PickOneRoomDfs(nums, 1, numsSize);
    return doFirst > notDoFirst ? doFirst : notDoFirst;
}

int main()
{
    int nums[] = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,
    128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = rob(nums, numsSize);
    printf("%d\n", ret);
    //printf("%d\n", g_max);
}
