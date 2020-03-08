/**
	2.八皇后问题
	描述：4*4的格子，皇后要在格子上，不能互相攻击。可以攻击的规则是左右上下，及45度角。求有多少中状态？
	
	其实不用二维数组，用一个queue_pos的一维数组，表示每一列皇后所在的行号。那么用深度搜索，step在这里定义就是部署一个皇后；广度是必需在每个step必须完成的，在这里就

是部署在index列的某一行。
*/
#include<stdio.h>
#include<stdlib.h>
#define N 8
int queue_pos[N] = {0};
static int g_kind = 0;
void step(int index)
{
	int i = 0;
	int j = 0;
	//printf("?\n");
	// 部署到第index个皇后，就认为是是一种OK的状态
	if (index == N + 1) {
		g_kind++;	
	}
	// option广度上需要判断是否合理,从index列的0行到N行都试一下
	for (i = 0 ; i < N; i++) {
		//尝试部署一个
		queue_pos[index] = i;
		// 判断是否符合不攻击的状态，第一个判断是这个位置不能与前面的位置出现在同一行
		for (j = 0; j < index; j++) {
			// 不能在同一行
			if (queue_pos[j] == queue_pos[index]) {
				break;
			}
			// 不能在45度
			if (abs(queue_pos[index] - queue_pos[j]) == abs(index - j)) {
				break;
			}
		}
		if (j >= index) {
			 step(index + 1);
		}
		
	}

}
int main()
{
	step(0);
	printf("hello%d\n",g_kind);
}