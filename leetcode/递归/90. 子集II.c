/*
输入: nums = [1,2,3]
输出:
[
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
]

*/
#include<stdio.h>
#include<stdlib.h>

/*void step(int* nums, int* ans, int* res_col, int box, int start, int ans_index)
{
	int i;
	if (box == start) {
		memcpy(res[g_count], ans, sizeof(int) * (ans_index));
		res_col[g_count] = ans_index;
		printf("%d\n",g_count);
		for (i = 0; i < ans_index; i++) {
			printf("%d ",res[g_count][i]);
		}
		printf("\n");
		g_count++;
		return;
	}
	for (i = start; i < box; i++) {
		
		if (vis[i][0] == 0) {
			vis[i][0] = 1;
			ans[ans_index] = nums[i];
			step(nums, ans, res_col, box, i + 1, ans_index + 1);
			vis[i][0] = 0;
		}
		if (vis[i][1] == 0) {
			step(nums, ans, res_col, box, i + 1, ans_index);
			vis[i][1] == 1;
		}
		
	}
}*/

#define MAX 1000
int** res = NULL;
int g_count = 0;
int my_cmp(const void* a, const void* b){
	int* pa = (int*)a;
	int* pb = (int*)b;
	return *pa - *pb;
}
void step(int* nums, int numsSize, int* ans, int box, int* res_col, int ans_index, int start)
{
	int i;
	if (box == numsSize) {
		memcpy(res[g_count], ans, sizeof(int) * (ans_index));
		res_col[g_count] = ans_index;
		//memset(ans, 0, numsSize);
		g_count++;
		return;
	}	
	for (i = start; i < numsSize; i++) {
		// 先记录当前数字
		ans[ans_index] = nums[i];
		// 当前的数字当选了，box+1,ans_index+1
		step(nums, numsSize, ans, box + 1, res_col, ans_index + 1, i + 1);
		
		// 当遇到重复的时候（i > 0 && nums[i] == nums[i - 1]）注意了，并且前面一个答案和当前的一样（ans[ans_index - 1] == ans[ans_index]）
		// 就不让box+1
		if (i > 0 && nums[i] == nums[i - 1] && ans_index > 0 && ans[ans_index - 1] == ans[ans_index]){
			continue;
		}
		// 当前的数字不当选，box仍然+1，认为处理了一个盒子，但是ans_index不能加
		step(nums, numsSize, ans, box + 1,res_col, ans_index, i + 1);
	}
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i =0;
	int sum = 1;
	int* res_col = NULL;
    int* ans = NULL;
	
	g_count = 0;

	// 计算结果数
	for (i = 0; i < numsSize; i++) {
		sum *= 2;
	}
	*returnSize = sum;

	// 为结果分配空间
	res = (int**)malloc(sizeof(int*) * (*returnSize));
	res_col = (int*)malloc(sizeof(int) * (*returnSize));
	memset(res_col, 0, sizeof(int) * (*returnSize));
	for (i = 0; i < *returnSize; i++) {
		res[i] = malloc(sizeof(int) * (numsSize));
		memset(res[i], 0, sizeof(int) * numsSize);
	}

	// 保存单次的结果
	ans = (int*)malloc(sizeof(int) * numsSize);
	memset(ans, 0, numsSize);
	
	qsort(nums, numsSize, sizeof(int), my_cmp);

	step(nums, numsSize, ans, 0, res_col, 0 ,0);
	*returnColumnSizes = res_col;
	*returnSize = g_count;
	return res;
}



int main()
{
	int** res1 = NULL;
	int nums[] = {4,4,4,1,4};
	int **res1_col = (int**)malloc(sizeof(int*)); 
	int returnSize = 0;
	int i, j;
	*res1_col = NULL;
	//printf("%d\n",*res1_col);
	res1 = subsetsWithDup(nums, sizeof(nums) / sizeof(nums[0]), &returnSize, (int**)res1_col);
	for (i =0 ; i < returnSize; i++) {
		for (j = 0; j < (*res1_col)[i]; j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	printf("size %d\n",returnSize);

}