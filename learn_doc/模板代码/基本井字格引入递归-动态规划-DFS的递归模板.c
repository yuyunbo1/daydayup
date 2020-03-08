/**
1.基本井字格
	
	4行3列的格子，从（0，0）到端点的（4，3）不走远路的话可以有多少种走法？
	递归
*/
#include<stdio.h>
#include<stdlib.h>
int cache[100][100] = {0};
int f(int m,int n)
{
	if (m < 0 || n < 0) {
		return 0;
	}
	if (m == 0 && n == 0) {
		return 1;
	}
	if (cache[m][n] != 0) {
		return cache[m][n];
	}
	cache[m][n] = f(m - 1, n) + f(m, n - 1);
	return cache[m][n];
}
//动态规划
int dp[100][100] = {0};
int f_dp(int m,int n)
{
	int i = 0, j = 0;
	dp[0][0] = 1;
	for (i = 1; i <= n; i++) {
		dp[0][i] = 1;
	}
	for (i = 1; i <= m; i++) {
		dp[i][0] = 1;
	}
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return dp[m][n];
}
/*
	4行3列的格子，从（0，0）到端点的（4，3）可以走远路的话可以有多少种走法？
	（3）深度搜索（DFS）
		广度(BFS)一般用的少，深度(DFS)可以解决很多问题。与深度强相关的事回溯，属于一种编程技巧或者思路。
		A:回溯有2种写法，循环控制回溯路径，但是推荐用递归+cache的方法，因为特别容易看懂。
		B:套路话但很容易的写法，深度搜索上其实也有2格概念。深度对于每个题不一样，广度也不同。
		如在井字格上深度（step）是往前走一步，广度(option)是怎么走
*/
#define COL 5
#define ROW 4
int visited[10][10] = {0};
int step(int x, int y, int m, int n)
{
	int sum = 0;
	if (x == m && y == n) {
		return 1; // 走到目的地
	}
	if (x < 0 || y <0 || x > COL || y > ROW) {
		return 0; // 判断边界
	}
	if (visited[x][y] == 1) {
		return 0;
	}
	if (visited[x][y] == 1) {
		return 0;
	}
	visited[x][y] = 1; //踩脚印

	sum += step(x - 1,y,m,n); //向左
	sum += step(x + 1,y,m,n); //向右
	sum += step(x,y + 1,m,n); //向上
	sum += step(x,y - 1,m,n); //向下

	visited[x][y] = 0; //抹脚印
	return sum;
}
int main()
{
	printf("%d\n",f(10, 15));
	printf("%d\n",f_dp(10, 15));
	printf("%d\n",step(4, 4, 5, 4));
}