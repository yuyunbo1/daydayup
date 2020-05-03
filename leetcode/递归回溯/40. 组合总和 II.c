#include<stdio.h>
#include<stdlib.h>
int MyCmp(const void* a, const void* b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return *pa - *pb;
}
#define N 200
int ans[N] = {0};
int g_ans_count = 0;
int g_count = 0;
int g_resCol[N] = {0};
int vis[N] = {0};
void Step(int* candidates, int candidatesSize, int target, int** res, int startIndex, int curSum)
{
	int i;
	if (target == curSum) {
		memcpy(res[g_count], ans, sizeof(int) * g_ans_count);
		g_resCol[g_count] = g_ans_count;
		g_count++;
	}
	for (i = startIndex; i < candidatesSize; i++) {
		if (vis[i] == 1) {
			continue;
		}
		if (i > 0 && candidates[i - 1] == candidates[i] && vis[i - 1] == 0) {
			continue;
		}
		if (candidates[i] + curSum > target) {
			continue;
		}
		vis[i] = 1;
		ans[g_ans_count] = candidates[i];
		g_ans_count++;
		Step(candidates, candidatesSize, target, res, i + 1, curSum + candidates[i]);
		vis[i] = 0;
		g_ans_count--;
	}
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int** res = NULL;
	int i;
	res = (int**)malloc(sizeof(int*) * N);
	g_count = 0; 
	for (i = 0; i < N; i++) {
		res[i] = (int*)malloc(sizeof(int) * N);
		memset(res[i], 0 , sizeof(int) * N);
		ans[i] = 0;
		vis[i] = 0;
		g_resCol[i] = 0;
	}
	qsort(candidates, candidatesSize, sizeof(int), MyCmp);
	Step(candidates, candidatesSize, target, res, 0, 0);
	*returnSize = g_count;
	*returnColumnSizes = g_resCol;
	return res;
}
int main()
{
	int size = 0;
	int** res = NULL;
	int** col = (int**)malloc(sizeof(int*));
	int nums[] = { 10,1,2,3,3,7,6,6,1,5  };
	int i, j;
  	*col = NULL;
	res = combinationSum2(nums, sizeof(nums) / sizeof(nums[0]), 8, &size, col);
	for (i = 0; i < size; i++) {
		for (j = 0; j < (*col)[i]; j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	printf("size:%d\n",size);
}