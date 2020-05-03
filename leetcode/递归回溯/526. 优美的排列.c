#include<stdio.h>
#include<stdlib.h>
/*
输入: 2
输出: 2
解释:

第 1 个优美的排列是 [1, 2]:
  第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
  第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-arrangement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
