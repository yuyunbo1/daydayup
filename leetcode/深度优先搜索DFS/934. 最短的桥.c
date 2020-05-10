#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int dir[][2] = {
    {0,-1},
    {0,1},
    {-1,0},
    {1,0},
};
int g_find = 0;
#define MAX 200
typedef struct Queue {
    int head;
    int tail;
    int size;
    int A[MAX][2];
}QUEUE_T;
void QueueReInit(QUEUE_T* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    memset(queue->A, 0 , MAX * 2* sizeof(int));
}
int QueueIsFull(QUEUE_T* queue)
{
    return queue->size == MAX ? 1 : 0;
}
int QueueIsEmpty(QUEUE_T* queue)
{
    return queue->size == 0 ? 1 : 0;
}
void QueuePush(QUEUE_T* queue, int x, int y)
{
    if (QueueIsFull(queue) == 1) {
        return;
    }
    queue->A[queue->tail][0] = x;
    queue->A[queue->tail][1] = y;
    queue->size++;
    queue->tail = (++queue->tail) % MAX;
}
void QueuePop(QUEUE_T* queue, int* x, int* y)
{
    if (QueueIsEmpty(queue) == 1) {
        return;
    }
    *x = queue->A[queue->head][0];
    *y = queue->A[queue->head][1];
    queue->size--;
    queue->head = (++queue->head) % MAX;
}
void ColorDfs(int** A, int rowSize, int colSize, int curX, int curY)
{
    int i, j;
    int nextX, nextY;
    for (i = 0; i < 4; i++) {
        nextX = curX + dir[i][0];
        nextY = curY + dir[i][1];
        if (nextX < 0 || nextY < 0 || nextX >= rowSize || nextY >= colSize) {
            continue;
        }
        if (A[nextX][nextY] != 1) {
            continue;
        }
        /**染色2*/
        A[nextX][nextY] = 2;
        ColorDfs(A, rowSize, colSize, nextX, nextY);
    }
}
int g_BfsLevel = 0;
void ExpandBfs(int** A, int rowSize, int colSize, int startX, int startY)
{
    QUEUE_T queue = {0};
    int vis[MAX][MAX] = {0};
    int curX = 0, curY = 0;
    int nextX = 0, nextY = 0;
    int levelSize;
    int i,j;
    QueueReInit(&queue);
    vis[startX][startY] = 1;
    QueuePush(&queue, startX, startY);
    while (QueueIsEmpty(&queue) != 1) {
        levelSize = queue.size;
        for (i = 0; i < levelSize; i++) {
            QueuePop(&queue, &curX, &curY);
            for (j = 0; j < 4; j++) {
                nextX = curX + dir[j][0];
                nextY = curY + dir[j][1];
                if (nextX < 0 || nextX >= rowSize || nextY < 0 || nextY >= colSize) {
                    continue;
                }
                if (A[nextX][nextY] == 2 || vis[nextX][nextY] == 1) {
                    continue;
                }
                // 找到
                if (A[nextX][nextY] == 1) {
                    g_find = 1;
                    return;
                }
                // 标记
                vis[nextX][nextY] = 1;
                QueuePush(&queue, nextX, nextY);
            }
        }
        g_BfsLevel++;
    }


}
int shortestBridge(int** A, int ASize, int* AColSize)
{
    int i, j;
    int min = INT_MAX;
    int color = 0;
    /**随便染色一个岛屿*/
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < AColSize[0]; j++) {
            if (A[i][j] == 1) {
                A[i][j] = 2;
                ColorDfs(A, ASize, AColSize[0], i ,j);
                break;
            }
        }
        if (j < AColSize[0]) {
            break;
        }
    }
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < AColSize[0]; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    /**染色之后，选取一个岛屿的所有点进行都进行一遍扩散，寻找最小的*/
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < AColSize[0]; j++) {
            if (A[i][j] == 2) {
                g_BfsLevel = 0;
                g_find = 0;
                ExpandBfs(A, ASize, AColSize[0], i ,j);
                if (g_find == 1) {
                    min = min > g_BfsLevel ? g_BfsLevel : min;
                }
            }
        }
    }
    return min;
}

int main() {
    int A[][6] = {
        {0,0,0,0,0,0},
        {0,1,0,0,0,0},
        {1,1,0,0,0,0},
        {1,1,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,1,1,0,0},
       /*{0,1,0,0,0},
       {0,1,0,1,1},
       {0,0,0,0,1},
       {0,0,0,0,0},
       {0,0,0,0,0},*/
       /*
       {1,1,1,1,1},
       {1,0,0,0,1},
       {1,0,1,0,1},
       {1,0,0,0,1},
       {1,1,1,1,1},
       */
       /*{0,1,0},
       {0,0,0},
       {0,0,1},*/
    };
    int ASize = sizeof(A) / sizeof(A[0]);
    int AColSize = sizeof(A[0]) / sizeof(A[0][0]);
    int** mat = calloc(ASize, sizeof(int*));
    int i, j, ret;
    for (i = 0; i < ASize; i++) {
        mat[i] = (int*)calloc(AColSize, sizeof(int));
        memcpy(mat[i], (int*)A[i], AColSize * sizeof(int));
    }

    ret = shortestBridge(mat, ASize, &AColSize);
    printf("%d\n", ret);
}
