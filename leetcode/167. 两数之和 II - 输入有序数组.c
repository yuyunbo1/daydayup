#include<stdio.h>
#include<stdlib.h>
/*
给定一个已按照升序排列?的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1?必须小于?index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
    int j = numsSize - 1;
	int* res = (int*)malloc(sizeof(int) * 2);
	memset(res, 0, sizeof(int) * 2);
	while(i < j) {
		if (nums[i] + nums[j] > target) {
			j--;
			continue;
		}
		if (nums[i] + nums[j] < target) {
			i++;
			continue;
		}
		res[0] = i + 1;
		res[1] = j + 1;
		break;
	}
	*returnSize = 2;
	return res;
}

int main()
{
	int nums[] = {3, 3};
	int *res = NULL;
	int size = 0;
	int i;
	res = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 6, &size);
	printf("res[0] %d res[1] %d\n",res[0], res[1]);
}