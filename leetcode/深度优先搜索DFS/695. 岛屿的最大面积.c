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
        /**����Ѿ�������*/
        grid[nextX][nextY] = 0;
        /**�ȹ��Ľ�ӡ����*/
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
            /**�������Ѿ�����,�������ֱ�Ӳ���grid��visʹ��*/
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
���鼯˼�룺
1.����grid����ʼ�����鼯
2.����grid,�Է�0�Ľ������ܺϲ�
3.����grid,�Է�0�Ľڵ�Ѱ������mapͳ����ͬ���ڵ�����ֵ*/
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
        /**����Ѿ�������*/
        grid[nextX][nextY] = 0;
        /**�ȹ��Ľ�ӡ����*/
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
            /**�������Ѿ�����,�������ֱ�Ӳ���grid��visʹ��*/
            grid[i][j] = 0;
            g_curMax = 1;
            LongestDepthDfs(grid, gridSize, gridColSize[0], i ,j);
            // g_curMax��ʾ�������ѵ�������
            maxArea = maxArea > g_curMax ? maxArea : g_curMax;
        }
    }
    return maxArea;
}
#endif

