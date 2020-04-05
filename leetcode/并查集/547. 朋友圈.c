#include<stdio.h>
#include<stdlib.h>
/*
并查集做法： 初始朋友圈数为Msize（自己和自己算一个圈g_cycle = MSize）,能merge的圈就少一个(g_cycke--)，根据输入数组维护并查集，维护好了之后，圈就算出来了。

对于数组元素为1的才需要去merge，且下表i、j不相同才去merge
*/
int g_cycle = 0;
static int box = 0;
int FindRootCompress(int* parent, int x)
{
    box++;
    printf("x %d box %d\n",x, box);
    if (parent[x] == x) {
        return x;
    }
    parent[x] = FindRootCompress(parent, parent[x]);
    return parent[x];
}
int MergeEleByRank(int* parent ,int* rank, int x, int y)
{
    int xRoot, yRoot;
    xRoot = FindRootCompress(parent, x);
    yRoot = FindRootCompress(parent, y);
    if (xRoot == yRoot) {
        return 0;
    }
    g_cycle--;
    if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    }
    else if(rank[yRoot] < rank[xRoot]) {
        parent[xRoot] = yRoot;
    }
    else {
        parent[xRoot] = yRoot;
        rank[xRoot]++;
    }
    return 1;
}
int findCircleNum(int** M, int MSize, int* MColSize)
{
    int* parent = NULL;
    int* rank = NULL;
    int i, j, iRoot, jRoot;
    int max = (MSize < MColSize[0]) ? MColSize[0] : MSize;
    parent = (int*)calloc(max, sizeof(int));
    rank = (int*)calloc(max, sizeof(int));
    g_cycle = MSize;
    // 初始化，因为和自己都是在同一个朋友圈
    for(i = 0; i < max; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    for (i = 0; i < MSize; i++) {
        for (j = i + 1; j < MColSize[0]; j++) {
            if (M[i][j] != 1) {
                continue;
            }
            MergeEleByRank(parent, rank, i, j);
        }
    }
    return g_cycle;
}
int main()
{
    int grid[][3] = {
        {1,1,0},
        {1,1,1},
        {0,1,1},
    };
    int i;
    int res = 0;
    int colSize = sizeof(grid[0]) / sizeof(grid[0][0]);
    int** M = (int**)calloc(sizeof(grid) / sizeof(grid[0]), sizeof(int*));
    for (i = 0; i < sizeof(grid) / sizeof(grid[0]); i++) {
        M[i] = (int*)calloc(sizeof(grid[0]) / sizeof(grid[0][0]), sizeof(int));
        memcpy(M[i], grid[i], sizeof(grid[0]) / sizeof(grid[0][0]) * sizeof(int));
    }
    res = findCircleNum(M, sizeof(grid) / sizeof(grid[0]), &colSize);
    printf("%d\n", res);
}
