#include<stdio.h>
#include<stdlib.h>
#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)
typedef struct {
    int index;
    int difficultyValue;
    int prifitValue;
}DIFFICULTY_T;

int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa > *pb;
}
int MyCmp1(const void* a, const void* b)
{
    DIFFICULTY_T* pa = (DIFFICULTY_T*)a;
    DIFFICULTY_T* pb = (DIFFICULTY_T*)b;
    return pa->difficultyValue > pb->difficultyValue;
}
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    int max = 0;
    int i = 0;
    int j = 0;
    int startIndex = 0;
    int k = 0;
    int tmpMax;
    qsort(worker, workerSize, sizeof(int), MyCmp);
    DIFFICULTY_T* diff = (DIFFICULTY_T*)calloc(difficultySize, sizeof(DIFFICULTY_T));
    for (j = 0; j < difficultySize; j++) {
        diff[j].index = j;
        diff[j].difficultyValue = difficulty[j];
        diff[j].prifitValue = profit[j];
    }
    qsort(diff, difficultySize, sizeof(DIFFICULTY_T), MyCmp1);

    while (i < workerSize) {
        for (j = startIndex; j < difficultySize; j++) {
            if (worker[i] >= diff[j].difficultyValue) {
                continue;
            }
            startIndex = j;
            break;
        }
        // j < 0说明这个工人找不到工作
        if (j == 0) {
                i++;
            continue;
        }
        tmpMax = -1;
        for (k = 0; k < j; k++) {
            tmpMax = GET_MAX(tmpMax, diff[k].prifitValue);
        }
        max += tmpMax;
        i++;
        while (i < workerSize) {
            if (worker[i] == worker[i - 1]) {
                max += tmpMax;
                i++;
            } else {
                break;
            }
        }
    }
    return max;
}
int main()
{
    /*int difficulty[] = {85,47,57};
    int profit[] = {24,66,99};
    int worker[] = {40,25,25};*/
    /*int difficulty[] = {2,4,6,8,10};
    int profit[] = {10,20,30,40,50};
    int worker[] = {4,5,6,7};*/
    int difficulty[] = {7,20,68};
    int profit[] = {26,28,57};
    int worker[] = {71,20,71};
    int workerSize = sizeof(worker) / sizeof(worker[0]);
    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int maxProfit = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);
    printf("%d\n", maxProfit);
}
