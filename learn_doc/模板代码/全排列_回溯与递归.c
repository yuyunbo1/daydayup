#define N 100
int vis[N] = {0};
int ans[N] = {0};
int count = 0;

int step(int* nums, int numsSize, int** res, int n)
{
	int i = 0, j = 0;
	// 放完了的话，就要记录值并返回
	if (n == numsSize) {
		for (i = 0; i < numsSize; i++) {
			//res[count][i] = ans[i];
			res[count][i] = ans[i];
		}
		count++;

		return 0;
	}

	for (i = 0; i < numsSize; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			ans[n] = nums[i];
			//printf("now conut = %d,n=%d,i=%d\n",count, n,i);
			step(nums, numsSize, res, n + 1);//第一次肯定打【1，2，3】，然后回退输入【2，】
			vis[i] = 0;
		}
	}
	return 0;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
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
	for (i = 0; i <100; i++) {
		vis[i] = 0;
		ans[i] = 0;
	}
	step(nums, numsSize, res, 0);

	*returnColumnSizes = resCol;

	return res;
}