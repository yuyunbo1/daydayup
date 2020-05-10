int dir[][2] = {
    {0,-1},
    {0,1},
    {-1,0},
    {1,0},
};
int g_curMax = 0;
void LongestDepthDfs(int** grid, int rowSize, int colSize, int curX, int curY)
{
    int k;
    int nextX, nextY;
    for (k = 0; k < 4; k++) {
        nextX = curX + dir[k][0];
        nextY = curY + dir[k][1];
        if (nextX < 0 || nextY < 0 || nextX >= rowSize || nextY >= colSize) {
            continue;
        }
        if (grid[nextX][nextY] == 0) {
            continue;
        }
        /**标记已经被访问*/
        grid[nextX][nextY] = 0;
        /**踩过的脚印增加*/
        g_curMax++;
        LongestDepthDfs(grid, rowSize, colSize, nextX, nextY);
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int maxArea = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            curMax = 0;
            /**标记起点已经被踩,这里可以直接采用grid当vis使用*/
            grid[i][j] = 0;
            g_curMax = 0;
            LongestDepthDfs();
            maxArea = maxArea > g_curMax ? maxArea : g_curMax;
        }
    }
    return maxArea;
}
#if 0
/**
并查集思想：
1.遍历grid并初始化并查集
2.遍历grid,对非0的进行四周合并
3.遍历grid,对非0的节点寻根，用map统计相同根节点的最大值*/
int dir[][2] = {
    {0,-1},
    {0,1},
    {-1,0},
    {1,0},
};
int g_curMax = 0;
void LongestDepthDfs(int** grid, int rowSize, int colSize, int curX, int curY)
{
    int k;
    int nextX, nextY;
    for (k = 0; k < 4; k++) {
        nextX = curX + dir[k][0];
        nextY = curY + dir[k][1];
        if (nextX < 0 || nextY < 0 || nextX >= rowSize || nextY >= colSize) {
            continue;
        }
        if (grid[nextX][nextY] == 0) {
            continue;
        }
        /**标记已经被访问*/
        grid[nextX][nextY] = 0;
        /**踩过的脚印增加*/
        g_curMax++;
        LongestDepthDfs(grid, rowSize, colSize, nextX, nextY);
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int i, j;
    int maxArea = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            /**标记起点已经被踩,这里可以直接采用grid当vis使用*/
            grid[i][j] = 0;
            g_curMax = 1;
            LongestDepthDfs(grid, gridSize, gridColSize[0], i ,j);
            // g_curMax表示本地深搜的最大点数
            maxArea = maxArea > g_curMax ? maxArea : g_curMax;
        }
    }
    return maxArea;
}
#endif

