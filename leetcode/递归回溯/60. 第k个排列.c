#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int g_count = 0;
int vis[MAX] = {0};
void step(char *res, char* ans, int n, int k, int box)
{
    int i;
    if (g_count >= k) {
        return;
    }
    if (box == n) {
        ans[box] = '\0';
        g_count++;
        if (g_count == k) {
            memcpy(res, ans, strlen(ans));
        }
        return;
    }
    for (i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            continue;
        }
        vis[i] = 1;
        ans[box] = i + '0';
        step(res, ans, n, k, box + 1);
        vis[i] = 0;
    }
}
char * getPermutation(int n, int k)
{
    char *res = NULL;
    char *ans = NULL;
    g_count = 0;
    res = (char*)calloc(n + 1, sizeof(char));
    ans = (char*)calloc(n + 1, sizeof(char));
    memset(vis, 0, sizeof(int) * MAX);
    step(res, ans, n, k, 0);
    free(ans);
    ans = NULL;
    return res;
}
int main()
{
    char *res = getPermutation(3, 3);
    printf("%s\n",res);
    free(res);
    res = NULL;
    return 0;
}
