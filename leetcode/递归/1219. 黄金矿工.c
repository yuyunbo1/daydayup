#include<stdio.h>
#include<stdlib.h>
int g_max = -1;
int g_count = 0;
int g_dir[][2] = {
    {0, -1},
    {0, 1},
    {-1,0},
    {1,0},
};

void Dfs(int** grid, int** vis, int maxX, int maxY, int x, int y, int cur)
{
    int i, j;
    int nextX, nextY;
    g_max = (g_max < cur) ? (cur) : (g_max);
    for (i = 0; i < sizeof(g_dir) / sizeof(g_dir[0]); i++) {
        nextX = x + g_dir[i][0];
        nextY = y + g_dir[i][1];
        // 非法的不用继续
        if (nextX < 0 || nextY < 0 || nextX >= maxX || nextY >= maxY) {
            continue;
        }
        // 访问过的不挖
        if (vis[nextX][nextY] == 1) {
            continue;
        }
        // 为0的不去挖，并标记为永不访问
        if (grid[nextX][nextY] == 0) {
            vis[nextX][nextY] = 1;
            continue;
        }
        vis[nextX][nextY] = 1;
        Dfs(grid, vis, maxX, maxY, nextX, nextY, cur + grid[nextX][nextY]);
        vis[nextX][nextY] = 0;
    }

}

int getMaximumGold(int** grid, int gridSize, int* gridColSize)
{
    int row = gridSize, col = gridColSize[0];
    int i, j, k;
    int **vis = NULL;
    int*** router =NULL;//(int***)calloc(row , sizeof(int**));
    vis = (int**)calloc(row, sizeof(int*));
    g_max = -1;
    for(i = 0; i < row; i++) {
        vis[i] = (int*)calloc(col, sizeof(int));
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            for (k = 0; k < row; k++) {
                memset(vis[k], 0, col * sizeof(int));
            }
            vis[i][j] = 1;
            if (i == 4 && j == 2) {
                printf("%d %d:%d\n",i,j,vis[3][5]);
            }

            Dfs(grid, vis, row, col, i , j, grid[i][j]);
        }
    }
    for(i = 0; i < row; i++) {
        free(vis[i]);
    }
    free(vis);
    return g_max;
}
int main()
{
    int res = 0;
    int* colSize = NULL;
    /*int tmpGrid[][3] = {
        {0,6,0},
        {5,8,7},
        {0,9,0},
    };*/ //24
    int tmpGrid[][6] = {
        {1,0,7,0,0,0},
        {2,0,6,0,1,0},
        {3,5,6,7,4,2},
        {4,3,1,0,2,0},
        {3,0,5,0,20,0},
    };
    int i ,j;
    int** grid = (int**)calloc(sizeof(tmpGrid) / sizeof(tmpGrid[0]), sizeof(int*));
    colSize = (int*)calloc(sizeof(tmpGrid) / sizeof(tmpGrid[0]), sizeof(int));
    memset(colSize, 0, sizeof(tmpGrid[0]) / sizeof(tmpGrid[0][0]) * sizeof(int));
    colSize[0] = sizeof(tmpGrid[0]) / sizeof(tmpGrid[0][0]);
    for (i = 0; i < sizeof(tmpGrid) / sizeof(tmpGrid[0]); i++) {
        grid[i] = (int*)calloc(sizeof(tmpGrid[0]) / sizeof(tmpGrid[0][0]), sizeof(int));
        memcpy(grid[i], tmpGrid[i], sizeof(tmpGrid[0]) / sizeof(tmpGrid[0][0]) * sizeof(int));
    }
    for (i = 0; i < sizeof(tmpGrid) / sizeof(tmpGrid[0]); i++) {
        for (j = 0; j < sizeof(tmpGrid[0]) / sizeof(tmpGrid[0][0]); j++) {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    res = getMaximumGold(grid, sizeof(tmpGrid) / sizeof(tmpGrid[0]), colSize);
    for (i = 0; i < sizeof(tmpGrid) / sizeof(tmpGrid[0]); i++) {
        free(grid[i]);
    }
    free(grid);
    grid = NULL;
    free(colSize);
    colSize = NULL;
    printf("%d\n", res);
    return 0;
}
