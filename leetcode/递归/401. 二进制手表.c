#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*
这里的step定义为放一个灯；option可以定义为从0-10个灯选择位置
*/
/*
这里的step定义为放一个灯；option可以定义为从0-10个灯选择位置
*/
// 用于计数
int g_count = 0;

char **res = NULL;
int cal[] = {8,4,2,1,32,16,8,4,2,1};
// 10个灯最多有1024种情况
#define MAX 0xfffff
// 每个字符串最长为6 如12:00
#define COL_MAX 6


void step(int* vis, int hour, int min, int start, int num)
{
	int i;
	if (num == 0) {
		sprintf(res[g_count], "%d:%02d", hour,min);
		g_count++;
		return;
	}
	for (i = start; i <= 9; i++) {
		
		if (vis[i] != 0) {
			continue;
		}
		vis[i] = 1;
		if (i >= 6 && hour + cal[i] >= 12) {
			vis[i] = 0;
			continue;
		}
		if (i < 6 && min + cal[i] >= 60) {
			vis[i] = 0;
			continue;
		}
		if (i >= 6) {
			step(vis, hour + cal[i], min, i + 1, num - 1);
            vis[i] = 0;
		}
		else {
			step(vis, hour, min + cal[i], i + 1, num - 1);
            vis[i] = 0;
		}
		
	}
}
char ** readBinaryWatch(int num, int* returnSize){
	int vis[10] = {0};
	int i;
	res = (char**)malloc(sizeof(char*) * MAX);
	for (i = 0; i < MAX; i++) {
		res[i] = (char*)malloc(sizeof(char) * COL_MAX);
		memset(res[i], 0, sizeof(char) * COL_MAX);
	}
	g_count = 0;
	step(vis, 0 ,0, 0, num);
	*returnSize = g_count;
	return res;
	
}
int main()
{
	char **res1 = NULL;
	int count = 0;
	int i;
	time_t start, end;
	time(&start);
	res1 = readBinaryWatch(2, &count);
	time(&end);
	
	if (res1 != NULL) {
		for (i = 0; i < count; i++) {
			printf("%s\n",res1[i]);
		}
	}
	printf("end-start:%f\n",difftime(end, start));
	printf("count = %d\n",count);
}