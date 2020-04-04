#include<stdio.h>
#include<stdlib.h>
int flag = 0;
void Step(int *res, int *vis, int n, int box)
{
    int i;
    int next;
    if (box == ((1 << n) -1)) {
        return;
    }

    for (i = 0; i < n; i++) {
        next = res[box] ^ (1 << i);
        if (vis[next] == 1) {
            continue;
        }
        if (flag == 1) {
            return;
        }
        vis[next] = 1;
        res[box + 1] = next;
        Step(res, vis, n, box + 1);
        vis[next] = 0;
        return;  // 这一句一定不能少，否则找到了一组，还会继续for循环往下
    }
}
int* grayCode(int n, int* returnSize)
{
    int *res = NULL;
    int *vis = NULL;
    flag = 0;
    *returnSize = 1 << n;
    res = (int*)calloc(*returnSize, sizeof(int));
    vis = (int*)calloc(*returnSize, sizeof(int));
    vis[0] = 1;
    Step(res, vis , n, 0);
    return res;
}
int main()
{
    int *res = NULL;
    int size = 0;
    int i;

    res = grayCode(5, &size);
    for (i = 0; i < size; i++) {
        printf("%d ", res[i]);
    }
    printf("\n%d\n", size);
    return 0;
}
/*
class Solution {
    List<Integer> res = new ArrayList();
    boolean[] visited;
    public List<Integer> grayCode(int n) {
        visited = new boolean[1<<n];
        dfs(0,n);
        return res;
    }

    boolean dfs(int cur,int n){
        if(res.size()==(1<<n))
            return true;
        res.add(cur);
        visited[cur]=true;
        for(int i=0;i<n;i++){
            int next = cur^(1<<i); //这里改变cur的某一位，用异或
            if(!visited[next]&&dfs(next,n))
                return true;
        }
        visited[cur] = false;
        return false;

    }
}
*/
