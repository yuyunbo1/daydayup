#include<stdio.h>
#include<stdlib.h>
#define N 250
int g_count = 0;
char*** res = NULL;
int* res_col = NULL;
int IsLoopBackStr(char *s, int start, int end)
{
    while(start < end && start < strlen(s) && end >= 0) {
        if (s[start] != s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void Step(char* s, int len, char** tmpStr, int curSum, int box)
{
    int i;
    int temp;
    if (curSum == len) {
        for (i = 0; i < box; i++) {
            temp = strlen(tmpStr[i]);
            memcpy(res[g_count][i], tmpStr[i], temp);
            res[g_count][i][temp] = '\0';
        }
        res_col[g_count] = box;
        g_count++;
        return;
    }
    for (i = 1; i <= len && i + curSum <= len; i++) {
        if (!IsLoopBackStr(s, curSum, curSum + i - 1)) {
            continue;
        }
        memcpy(tmpStr[box], &s[curSum], i);
        tmpStr[box][i] = '\0';
        Step(s, len, tmpStr, curSum + i, box + 1);
    }
}


char *** partition(char * s, int* returnSize, int** returnColumnSizes)
{
    int i, j;
    int len = strlen(s);
    char** tmpStr = NULL;
    g_count = 0;
    res = (char***)calloc(N, sizeof(char**));
    res_col = (int*)calloc(N, sizeof(int));
    tmpStr = (char**)calloc(N, sizeof(char*));
    for (i = 0; i < N; i++) {
        res[i] = (char**)calloc(N, sizeof(char*));
        tmpStr[i] = calloc(N, sizeof(char));
        for (j = 0; j < N; j++) {
            res[i][j] = (char*)calloc(N, sizeof(char));
        }
    }
    Step(s, len, tmpStr, 0, 0);
    free(tmpStr);
    tmpStr = NULL;
    *returnSize = g_count;
    *returnColumnSizes = res_col;
    return res;
}
int main()
{
    int size = 0;
    int **resCol = NULL;
    int i, j;
    resCol = (int**)calloc(1, sizeof(int*));
    partition("seeslaveidemonstrateyetartsnomedievalsees", &size, resCol);
    for (i = 0; i < size; i++) {
        for (j = 0; j < (*resCol)[i]; j++) {
            printf("%s ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
