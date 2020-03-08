/**
1.�������ָ�
	
	4��3�еĸ��ӣ��ӣ�0��0�����˵�ģ�4��3������Զ·�Ļ������ж������߷���
	�ݹ�
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
//��̬�滮
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
	4��3�еĸ��ӣ��ӣ�0��0�����˵�ģ�4��3��������Զ·�Ļ������ж������߷���
	��3�����������DFS��
		���(BFS)һ���õ��٣����(DFS)���Խ���ܶ����⡣�����ǿ��ص��»��ݣ�����һ�ֱ�̼��ɻ���˼·��
		A:������2��д����ѭ�����ƻ���·���������Ƽ��õݹ�+cache�ķ�������Ϊ�ر����׿�����
		B:��·���������׵�д���������������ʵҲ��2������ȶ���ÿ���ⲻһ�������Ҳ��ͬ��
		���ھ��ָ�����ȣ�step������ǰ��һ�������(option)����ô��
*/
#define COL 5
#define ROW 4
int visited[10][10] = {0};
int step(int x, int y, int m, int n)
{
	int sum = 0;
	if (x == m && y == n) {
		return 1; // �ߵ�Ŀ�ĵ�
	}
	if (x < 0 || y <0 || x > COL || y > ROW) {
		return 0; // �жϱ߽�
	}
	if (visited[x][y] == 1) {
		return 0;
	}
	if (visited[x][y] == 1) {
		return 0;
	}
	visited[x][y] = 1; //�Ƚ�ӡ

	sum += step(x - 1,y,m,n); //����
	sum += step(x + 1,y,m,n); //����
	sum += step(x,y + 1,m,n); //����
	sum += step(x,y - 1,m,n); //����

	visited[x][y] = 0; //Ĩ��ӡ
	return sum;
}
int main()
{
	printf("%d\n",f(10, 15));
	printf("%d\n",f_dp(10, 15));
	printf("%d\n",step(4, 4, 5, 4));
}