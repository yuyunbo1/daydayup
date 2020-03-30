#include<stdio.h>
#include<stdlib.h>
int MyCmp(const void* a, const void* b)
{
	int* pa = (int*)a;
	int *pb = (int*)b;
	return *pa - *pb;
}

int* twoSum1(int* nums, int numsSize, int target, int* returnSize){
	int* res = (int*)malloc(sizeof(int) * 2);
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	int* hashTable = NULL;
	int* find = NULL;
	int i, j;
	int ele = 0;
	memcpy(temp, nums, sizeof(int) * numsSize);
	memset(res, 0, sizeof(int) * 2);
	qsort(temp, numsSize, sizeof(int), MyCmp);
	hashTable = (int*)malloc(sizeof(int) * (temp[numsSize - 1] + 1));
	memset(hashTable, 0 , sizeof(int) * temp[numsSize - 1]);
	// ½¨Á¢hashTable
	for (i = 0; i < numsSize; i++) {
		//printf("%d ",temp[i]);
		hashTable[nums[i]] = i;
	}
	/*printf("\n");
	for (i = 0; i < numsSize; i++) {
	
		printf("%d %d \n",temp[i],hashTable[temp[i]]);
	}*/
	for (i = 0; i < numsSize; i++) {
		ele = target - nums[i];
		find = bsearch((int*)&ele, temp, numsSize, sizeof(int), MyCmp);
		if (find == NULL) {
			continue;
		}
		res[0] = i;
		res[1] = hashTable[*find];
		break;
	}
	*returnSize = 2;
	return res;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i, j;
	int* res = (int*)malloc(sizeof(int) * 2);
	memset(res, 0, sizeof(int) * 2);
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				res[0] = i;
				res[1] = j;
				break;
			}
		}
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