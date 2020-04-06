#include<stdio.h>
#include<stdlib.h>
int FindRootCompress(int* parent, int ele)
{
    if (ele == parent[ele]) {
        return ele;
    }
    parent[ele] = FindRootCompress(parent, parent[ele]);
    return parent[ele];
}

int MergeElemetByRank(int* parent, int* rank, int x, int y)
{
    int xRoot, yRoot;
    xRoot = FindRootCompress(parent, x);
    yRoot = FindRootCompress(parent, y);
    if (xRoot == yRoot) {
        return 0;
    }
    if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    }
    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    }
    if (rank[xRoot] == rank[yRoot]) {
        parent[xRoot] = yRoot;
        rank[yRoot]++;
    }
    return 1;
}

int regionsBySlashes(char ** grid, int gridSize)
{
    // 将每个小格子都用'/'或'\'分为4个小三角形,从上放逆时针数为0，1，2，3
    int* parent = NULL;
    int* rank = NULL;
    int i, j = 0, col ,temp;
    int ans = 0;
    parent = (int*)calloc(gridSize * gridSize * 4, sizeof(int));
    rank = (int*)calloc(gridSize * gridSize * 4, sizeof(int));
    for (i = 0; i < gridSize * gridSize * 4; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    // 开始处理网络数组
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            // 处理起始序号
            temp = i * gridSize * 4 + 4 * j;
            // 合并0，1；合并2，3
            if (grid[i][j] == '/') {
                MergeElemetByRank(parent, rank, temp + 0, temp + 1);
                MergeElemetByRank(parent, rank, temp + 2, temp + 3);
            }
            // 合并0，2；合并1，3
            if (grid[i][j] == '\\') {
                MergeElemetByRank(parent, rank, temp + 0, temp + 3);
                MergeElemetByRank(parent, rank, temp + 1, temp + 2);
            }
            // 空格其实不用管
            if (grid[i][j] == ' ') {
                MergeElemetByRank(parent, rank, temp + 0, temp + 1);
                MergeElemetByRank(parent, rank, temp + 2, temp + 3);
                MergeElemetByRank(parent, rank, temp + 1, temp + 2);
            }
            // 如果不是第一行，向上合并，即本格的0和上边的2和并
            if (i != 0) {
                MergeElemetByRank(parent, rank, temp + 0, temp - 4 * gridSize + 2);
            }
            // 不是最后一行的话，向下合并，即本格的2和下面的0
            if (i != gridSize - 1) {
                MergeElemetByRank(parent, rank, temp + 2, temp + 4 * gridSize + 0);
            }
            // 不是第一列的话，向左合并，1和3
            if (j != 0) {
                MergeElemetByRank(parent, rank, temp + 1, temp - 4 + 3);
            }
            // 不是最后一列的话，向右合并
            if (j != gridSize - 1) {
                MergeElemetByRank(parent, rank, temp + 3, temp + 4 + 1);
            }
        }
    }
    for (i = 0; i < gridSize * gridSize * 4; i++) {
            if (parent[i] == i) {
                ans++;
            }
    }
    free(parent);
    free(rank);
    return ans;
}

int main()
{
    char* tmpStr[] = {" /", "/ "};
    int i;
    int ret = 0;
    char** grid = (char**)calloc(sizeof(tmpStr) / sizeof(char*), sizeof(char*));
    for (i = 0; i < sizeof(tmpStr) / sizeof(char*); i++) {
        grid[i] = (char*)calloc(strlen(tmpStr) + 1, sizeof(char));
        memcpy(grid[i], tmpStr[i], strlen(tmpStr) + 1);
    }
    //printf("%c %c %d\n", grid[0][1], grid[0][3], strlen(tmpStr[0]));
    ret = regionsBySlashes(grid, 2);
    printf("ret %d\n", ret);
}
