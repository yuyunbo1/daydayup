#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
int vis[N] = {0};
int ans[N] = {0};
int count = 0;
int my_cmp(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;
	return *pa - *pb;
}

void step(int *nums, int numsSize, int** res, int box)
{
	int i;
	if (box == numsSize) {
		memcpy(res[count], ans, sizeof(int) * box);
		count++;
		return;
	}
	for (i = 0; i < numsSize; i++) {
		if (vis[i] == 1) {
			continue;
		}
		if (i > 0 && nums[i - 1] == nums[i] &&  vis[i - 1] == 1)
			continue;
		vis[i] = 1;
		ans[box] = nums[i];
		step(nums, numsSize, res, box +1);
		vis[i] = 0;
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i = 0,j = 0;
	int **res = NULL;
	int *resCol = NULL;
	*returnSize = 1;
	count = 0;
	// 计算空间大小
	for (i = numsSize; i > 0; i--) {
		*returnSize *= i;
	}
	res = (int**)malloc(sizeof(int*) * (*returnSize));
	memset(res, 0, sizeof(int*) * (*returnSize));
	resCol = (int*)malloc(sizeof(int) * (*returnSize));
	memset(resCol, 0, sizeof(int) * (*returnSize));

	for (i = 0; i < *returnSize; i++) {
		res[i] = (int*)malloc(sizeof(int) * numsSize);
		memset(res[i], 0, sizeof(int) * numsSize);
		resCol[i] = numsSize;
	}
	for (i = 0; i < 100; i++) {
		vis[i] = 0;
		ans[i] = 0;
	}
	qsort(nums, numsSize, sizeof(int), my_cmp);
	step(nums, numsSize, res, 0);
	*returnColumnSizes = resCol;
	*returnSize = count;
	return res;
}
int main()
{
	int** res = NULL;
	int returnSize = 0;
	int nums[] = { 1, 2, 1 , 3, 4, 3};
	int **res_col = (int**)malloc(sizeof(int*)); 
	int i, j;
	*res_col = NULL;
	res = permuteUnique(nums, sizeof(nums) / sizeof(nums[0]), &returnSize, res_col);
	for (i = 0; i < returnSize; i++) {
		for (j = 0; j < (*res_col)[i]; j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",returnSize);
}