#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define true 1
#define false 0

#define N 200
int vis[N][N] = {0};
static int dir[][2] = {
	{0, -1},
	{0,1},
	{1,0},
	{-1,0},
};
bool Step(char** board, int boardSize, int colSize, char* word, int box, int curX, int curY)
{
	int i = 0,j = 0;
	int nextX, nextY;
	int res = 0;
	// 保证每一步走对
	if (board[curX][curY] != word[box]) {
		return false;
	}
	
	if (box == strlen(word) - 1) {
		return true;
	}
	for (i = 0; i < 4; i++) {
		nextX = curX + dir[i][0];
		nextY = curY + dir[i][1];
		if (nextX < 0 || nextY < 0 || nextX >= boardSize || nextY >= colSize) {
			continue;
		}
		if (vis[nextX][nextY] == 1) {
			continue;
		}
		vis[nextX][nextY] = 1;
		res = Step(board, boardSize, colSize, word, box + 1, nextX, nextY);
		if (res) {
			return true;
		}
		vis[nextX][nextY] = 0;
	}
	return false;

}
bool exist(char** board, int boardSize, int* boardColSize, char* word){
	
	int i, j, res, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			vis[i][j] = 0;
		}
	}
	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardColSize[0]; j++) {
			// 每次递归前进行对vis清零
			for (k = 0; k < boardSize; k++) {
				memset(vis[k], 0 , sizeof(int) * boardColSize[0]);
			}
			vis[i][j] = 1;
			res = Step(board, boardSize, boardColSize[0], word, 0, i, j);
			if (res) {
				return res;
			}
		}
	}
	return false;
}
 
int main()
{
	int i, j;
	char **board = NULL;	
	/*char board1[][4] = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'},
	};*/
	char board1[][2] = {
		{'a', 'b'},
		{'c', 'd'},
	};
	/*char board1[][6] = {
		{'b','a','a','b','a','b'},
		{'a','b','a','a','a','a'},
		{'a','b','a','a','a','b'},
		{'a','b','a','b','b','a'},
		{'a','a','b','b','a','b'},
		{'a','a','b','b','b','a'},
		{'a','a','b','a','a','b'},
	};*/
	int* colSize = NULL;
	int res = 0;

	board = (char**)malloc(sizeof(char*) * sizeof(board1) / sizeof(board1[0]));
	colSize = (int*)malloc(sizeof(int) * sizeof(board1) / sizeof(board1[0]));
	for (i = 0; i < sizeof(board1) / sizeof(board1[0]); i++) {
		board[i] = (char*)malloc(sizeof(char) * sizeof(board1[0]));
		memcpy(board[i], board1[i], sizeof(board1[0]));
		colSize[i] = sizeof(board1[0]);
	}
	
	for (i = 0; i < sizeof(board1) / sizeof(board1[0]); i++) {
		for (j = 0; j < sizeof(board1[0]); j++) {
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	res = exist(board, sizeof(board1) / sizeof(board1[0]), colSize, "cdba");//aabbbbabbaababaaaabababbaaba
	
	printf("%d\n",res);

	for (i = 0; i < sizeof(board1) / sizeof(board1[0]); i++) {
		free(board[i]);
		board[i] = NULL;
	}
	free(colSize);
	free(board);
}