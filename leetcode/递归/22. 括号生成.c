#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define RES_SIZE_MAX 2000
char **res = NULL;
int g_count = 0;

/*这里step的定义就是放一个括号，直到放满2*box个盒子；option是放左还是放右;
放左的条件是只要左边的没放完，就可以一直放;

*/

void step(char* ans, int left, int right, int box) 
{
	if (left + right == box) {
		memcpy(res[g_count], ans, strlen(ans) + 1);
		g_count++;
		return;
	}
	
	if (left * 2 < box) {
		ans[left + right] = '(';
		step(ans, left +1, right, box);
	}
	
	if (right < left) {
		ans[left +right] = ')';
		step(ans, left, right +1, box);
	}
}
char ** generateParenthesis(int n, int* returnSize){
	
	char* ans;
	int i;
	g_count = 0;
	if (n == 0) {
		*returnSize = 0;
		return res;
	}
	if (n == 1) {
		*returnSize = 1;
		res = (char**)malloc(sizeof(char*)*2);
		res[0] = (char*)malloc(sizeof(char) * 3);
		memset(res[0], 0, 3);
		memcpy(res[0], "()",3);
		return res;
	}
	ans = (char*)malloc(sizeof(char) * (2 * n) + 1);
	memset(ans, 0, sizeof(char) * (2 * n) + 1);
	
	res = malloc(sizeof(char*) * RES_SIZE_MAX);
	for (i = 0; i < RES_SIZE_MAX; i++) {
		res[i] = malloc(sizeof(char) * (2 * n + 1));
		memset(res[i], 0 , sizeof(char) * (2 * n + 1));
	}
	step(ans, 0, 0 , 2 * n);
	*returnSize = g_count;
	free(ans);
	ans = NULL;
	return res;
}
int main()
{
	char** temp = NULL;
	int i;
	int size = 0;
	temp = generateParenthesis(8, &size);

	for (i = 0; i < size; i++) {
		printf("%s\n", temp[i]);
	}
	printf("size %d\n", size);
}