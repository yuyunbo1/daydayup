#include<stdlib.h>
#include<stdio.h>
int dir[4][2] = {
    {0, -1},
    {0, 1},
    {1, 0,},
    {-1, 0},
};
int FindRootCompress(int* parent, int ele)
{
    if (ele == parent[ele]) {
        return ele;
    }
    parent[ele] = FindRootCompress(parent, parent[ele]);
    return parent[ele];
}

int MergeElementByrank(int* parent, int* rank, int x, int y)
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
    if (rank[yRoot] > rank[xRoot]) {
        parent[xRoot] = yRoot;
    }
    if (rank[yRoot] == rank[xRoot]) {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
    return 1;
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int row = gridSize;
    int col = gridColSize[0];
    int i, j, k, root;
    int x, y;
    int ans = 0;
    int* parent = NULL;
    int* rank = NULL;

    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }

    parent = (int*)calloc(row * col, sizeof(int));
    rank = (int*)calloc(row * col, sizeof(int));
    for (i = 0 ;i < row * col; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            // 如果是0的话，将并查集对应节点的父节点置为-1
            if (grid[i][j] == '0') {
                parent[i * col + j] = -1;
                continue;
            }
            // 如果是1的话，需要对周围进行尝试
            for (k = 0; k < 4; k++) {
                x = i + dir[k][0];
                y = j + dir[k][1];
                if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == '0') {
                    continue;
                }
                MergeElementByrank(parent, rank, i * col + j, x *col + y);
            }
        }
    }
    for (i = 0; i < row * col; i++) {
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
    char nums[][20] = {
        /*{'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},*/
        /*{'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},*/
    {'1','0','0','1','1','1','0','1','1','0','0','0','0','0','0','0','0','0','0','0'},
	{'1','0','0','1','1','0','0','1','0','0','0','1','0','1','0','1','0','0','1','0' },
	{'0','0','0','1','1','1','1','0','1','0','1','1','0','0','0','0','1','0','1','0' },
	{'0','0','0','1','1','0','0','1','0','0','0','1','1','1','0','0','1','0','0','1' },
	{'0','0','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0' },
	{'1','0','0','0','0','1','0','1','0','1','1','0','0','0','0','0','0','1','0','1' },
	{'0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','1','0','1','0','1' },
	{'0','0','0','1','0','1','0','0','1','1','0','1','0','1','1','0','1','1','1','0' },
	{'0','0','0','0','1','0','0','1','1','0','0','0','0','1','0','0','0','1','0','1' },
	{'0','0','1','0','0','1','0','0','0','0','0','1','0','0','1','0','0','0','1','0' },
	{'1','0','0','1','0','0','0','0','0','0','0','1','0','0','1','0','1','0','1','0' },
	{'0','1','0','0','0','1','0','1','0','1','1','0','1','1','1','0','1','1','0','0' },
	{'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1' },
	{'0','1','0','0','1','1','1','0','0','0','1','1','1','1','1','0','1','0','0','0' },
	{'0','0','1','1','1','0','0','0','1','1','0','0','0','1','0','1','0','0','0','0' },
	{'1','0','0','1','0','1','0','0','0','0','1','0','0','0','1','0','1','0','1','1' },
	{'1','0','1','0','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','0' },
	{'0','1','1','0','0','0','1','1','1','0','1','0','1','0','1','1','1','1','0','0' },
	{'0','1','0','0','0','0','1','1','0','0','1','0','1','0','0','1','0','0','1','1' },
	{'0','0','0','0','0','0','1','1','1','1','0','1','0','0','0','1','1','0','0','0'},
    };
    char** grid = (char**)calloc(sizeof(nums) / sizeof(nums[0]), sizeof(char*));
    int i, j;
    int ret = 0;
    int colSize = sizeof(nums[i]) / sizeof(nums[i][0]);
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        grid[i] = (char*)calloc(grid[i], sizeof(nums[i]) / sizeof(nums[i][0]) * sizeof(char));
        memcpy(grid[i], nums[i], sizeof(nums[i]) / sizeof(nums[i][0]) * sizeof(char));
    }
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        for (j = 0; j < colSize; j++) {
            printf("%c ", nums[i][j]);
        }
        printf("\n");
    }
    ret = numIslands(grid, sizeof(nums) / sizeof(nums[0]), &colSize);
    printf("ret %d\n", ret);
    return 0;
}
