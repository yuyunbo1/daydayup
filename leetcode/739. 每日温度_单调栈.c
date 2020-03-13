#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * TSize);
	int* stack = (int*)malloc(sizeof(int) * TSize);
	int top = -1;
	int i = 0;
	int temp;
	memset(res,0,sizeof(int)*TSize);
	memset(stack,0,sizeof(int)*TSize);
	for (i = 0; i < TSize; i++) {
		while(top != -1 && T[i] > T[stack[top]]) {
			temp = stack[top];
			top--;
			res[temp] = i - temp;
		}
		top++;
		stack[top] = i;
	}
	*returnSize = TSize;
	return res;
}

#define N 100
int func(int *T, int size)
{
	int top = -1;
	int i, j, temp;
	int res[N] = {0};
	int stack[N] = {0};
	for (i = 0; i < size; i++) {
		while (top != -1 && T[i] > T[stack[top]]) {
			temp = stack[top];
			top--;
			res[temp] = i - temp;
		}
		top++;
		T[top] = i;
	}
	*returnSize = TSize;
	return res;
}

int func(int *T, int size)
{
	int i,j;
	int conut = 0;
	int max = -1;
	for (i = 0; i < size; i++) {
		count = 0;
		if (max < T[i]) {
			max = T[i];
		}
		for (j = i + 1; j < size; j++) {
			if (T[i] < T[j]) {
				count++;
				break;
			}
			count++;
		}
		if (T[i] is max) {
			res[i] = 0;
		}
		res[i] = count;
	}
}