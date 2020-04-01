#include<stdio.h>
#include<stdlib.h>
/*
����: 2
���: 2
����:

�� 1 �������������� [1, 2]:
  �� 1 ��λ�ã�i=1���ϵ�������1��1�ܱ� i��i=1������
  �� 2 ��λ�ã�i=2���ϵ�������2��2�ܱ� i��i=2������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/beautiful-arrangement
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#define MAX 100
int g_count = 0;
int vis[MAX] = {0};
void Step(int N, int box)
{
    int value;
    if (box == N + 1) {
        g_count++;
        return;
    }
    for (value = 1; value <= N; value++) {
        if (vis[value] == 1) {
            continue;
        }
        if (value % box == 0 || box % value == 0) {
            vis[value] = 1;
            Step(N, box + 1);
            vis[value] = 0;
        }
    }
}

int countArrangement(int N)
{
    int i;
    g_count = 0;
    memset(vis, 0, sizeof(int) * MAX);
    Step(N, 1);
    return g_count;
}
int main()
{
    int count = 0;
    count =countArrangement(2);
    printf("count:%d\n",count);
    return 0;
}
