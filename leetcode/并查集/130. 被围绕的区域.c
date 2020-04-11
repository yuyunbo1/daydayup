#include<stdio.h>
#include<stdlib.h>

int dir[][2] = {
    {0,-1},
    {0,1},
    {1,0},
    {-1,0},
};
int FindRootCompress(int* parent, int ele)
{
    if (parent[ele] == ele) {
        return ele;
    }
    parent[ele] = FindRootCompress(parent, parent[ele]);
    return parent[ele];
}
int MergeElementByRank(int* parent, int* rank, int x, int y)
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
        rank[xRoot]++;
        parent[yRoot] = xRoot;
    }
    return 1;
}
void solve(char** board, int boardSize, int* boardColSize){
    int row = boardSize;
    int col = boardColSize[0];
    int i ,j, k;
    int root1, root2, nextX, nextY;
    int* parent = NULL;
    int* rank = NULL;
    int max = row * col + 1;

    if (boardSize == 0 || boardColSize == NULL) {
        return;
    }

    parent = (int*)calloc(max, sizeof(int));
    rank = (int*)calloc(max, sizeof(int));
    for (i = 0; i < max; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == 'X') {
                continue;
            }
            // 如果是‘O’,先判断是否是边界，边界的话，先归档
            if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                MergeElementByRank(parent, rank, max - 1, i * col + j);
            }
            // 再和周围的'O'结合
           for (k = 0; k < 4; k++) {
            nextX = i + dir[k][0];
            nextY = j + dir[k][1];
            if (nextX < 0 || nextY < 0 || nextX >= row || nextY >= col) {
                continue;
            }
            if (board[nextX][nextY] == 'O') {
                MergeElementByRank(parent, rank, i * col + j, nextX * col + nextY);
            }
           }
        }
    }
    root1 = FindRootCompress(parent, max - 1);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == 'X') {
                continue;
            }
            root2 = FindRootCompress(parent, i * col + j);
            if (root1 != root2) {
                board[i][j] = 'X';
            }
        }
    }
    free(parent);
    free(rank);
    parent = NULL;
    rank = NULL;
}
int main()
{
    int i ,j;
    char tmp[][6] = {
	{'X','X','X','X','O','X'},
	{'O','X','X','O','O','X'},
	{'X','O','X','O','O','O'},
	{'X','O','O','O','X','O'},
	{'O','O','X','X','O','X'},
	{'X','O','X','O','X','X'},
};
    char** board = NULL;
    int colSize = sizeof(tmp[0]) / sizeof(tmp[0][0]);
    board = (char*)calloc(sizeof(tmp) / sizeof(tmp[0]), sizeof(char));
    for (i = 0; i < sizeof(tmp) / sizeof(tmp[0]); i++) {
        board[i] = (char*)calloc(sizeof(tmp[0]) / sizeof(tmp[0][0]) * sizeof(char), sizeof(char));
        memcpy(board[i], tmp[i], sizeof(tmp[0]) / sizeof(tmp[0][0]) * sizeof(char));
    }
    solve(board, sizeof(tmp) / sizeof(tmp[0]), &colSize);

    for (i = 0 ; i < sizeof(tmp) / sizeof(tmp[0]); i++) {
        for (j = 0 ; j < sizeof(tmp[0]) / sizeof(tmp[0][0]); j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
