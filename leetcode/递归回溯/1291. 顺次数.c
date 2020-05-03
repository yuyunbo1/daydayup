#define MAX 100
int g_count = 0;

// 循环加递归
void Dfs(int *res, int low, int high, int curSum)
{
    if (curSum > high) {
        return;
    }
    if (curSum >= low && high <= high) {
        res[g_count] = curSum;
        g_count++;
    }
    // 先预判
    if (curSum % 10 == 9) {
        return;
    }
    // curSum % 10 + 1 控制1234是连续的
    Dfs(res, low, high, curSum * 10 + curSum % 10 + 1);
}
int MyCmp(const void* a, const void* b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
int* sequentialDigits(int low, int high, int* returnSize){
    int *res = NULL;
    int i;
    g_count= 0;

    res = (int*)calloc(sizeof(int), MAX);
    //ForValue(res, low, high);
    for (i = 1; i <= 9; i++) {
        Dfs(res, low, high, i);
    }
    *returnSize = g_count;
    qsort(res, g_count, sizeof(int), MyCmp);
    return res;
}
/*
也有普通的解法
*/
// 普通解法
#define MAX 100
int g_count = 0;
int MyCmp(const void* a, const void* b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
void ForValue(int *res, int low, int high)
{
    int i, j;
    int curSum = 0;
    for (i = 1; i < 10; i++) {
        curSum = 0;
        for (j = i; j < 10; j++) {
            curSum = curSum * 10 + j;
            if (curSum < low) {
                continue;
            } else if (curSum > high) {
                break;
            } else {
                res[g_count] = curSum;
                g_count++;
            }
        }
    }
}

int* sequentialDigits(int low, int high, int* returnSize){
    int *res = NULL;
    g_count= 0;

    res = (int*)calloc(sizeof(int), MAX);
    ForValue(res, low, high);
    *returnSize = g_count;
    qsort(res, g_count, sizeof(int), MyCmp);
    return res;
}
