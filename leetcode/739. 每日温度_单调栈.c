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
