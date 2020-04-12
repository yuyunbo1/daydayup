#include<stdlib.h>
#include<stdio.h>
/**
ÊäÈë: nums = [4,5,6,7,0,1,2], target = 0
Êä³ö: 4
*/
int FindBond(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == nums[left]) {
            return mid;
        }
        if (nums[mid] > nums[left]) {
            left = mid;
            continue;
        }
        if (nums[mid] < nums[left]) {
            right = mid;
            continue;
        }
    }
    return -1;
}

int MyCmp(const void* a, const void* b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
int search(int* nums, int numsSize, int target)
{
    int index;
    int* ret = NULL;
    index = FindBond(nums, numsSize);
    if (index == -1) {
        return -1;
    }
    ret = bsearch(&target, (int*)nums, index + 1, sizeof(int), MyCmp);
    if (ret != NULL) {
        return (ret - nums);
    }
    ret = bsearch(&target, (int*)(&nums[index + 1]), numsSize - index - 1, sizeof(int), MyCmp);
    if (ret != NULL) {
        return (ret - nums);
    }
    return -1;
}
int main()
{
    int input[] = {4,5,6,7,0,1,2};
    int ret = 0;
    ret = search(input, sizeof(input) / sizeof(input[0]), 3);
    printf("ret %d\n", ret);
    //printf("%d %d\n",0x10, sizeof(int*));
    return 0;
}
