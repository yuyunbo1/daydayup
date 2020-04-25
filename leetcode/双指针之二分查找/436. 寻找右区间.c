/**
方法一：暴力求解超时了

#define GETMIN(x, y)  ((x) >= (y)) ? y :x;
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize)
{
    int * ans = NULL;
    int i, j;
    int minStart = 0xfffffff;
    int index;
    ans = (int*)calloc(intervalsSize, sizeof(int));

    for (i = 0; i < intervalsSize; i++) {
        index = -1;
        for (j = 0; j < intervalsSize; j++) {
            if (i == j) {
                continue;
            }
            if (intervals[i][1] <= intervals[j][0]) {
                minStart = GETMIN(minStart, intervals[j][0]);
                index = (minStart == intervals[j][0]) ? j : index;
            }
        }
        ans[i] = index;
    }
    *returnSize = intervalsSize;
    return ans;
}*/
#include<stdlib.h>
/**
1.按区间的第一个元素进行排序，然后遍历每个区间的元素1，对每个区间的元素1 x，查找第一个>=x 的区间，再映射到其ndex
2.难点如何在排序之后能捆绑区间在原集合中的序号
*/
/**
1.按区间的第一个元素进行排序，然后遍历每个区间的元素1，对每个区间的元素1 x，查找第一个>=x 的区间，再映射到其index
2.难点如何在排序之后能捆绑区间在原集合中的序号,只想到用结构体来捆绑，感觉应该有更好的方式
*/
typedef struct {
    int nums[2];
    int index;
}ELEMENT_T;
int MyCmp(const void* a, const void* b)
{
    ELEMENT_T* pa = (ELEMENT_T*)a;
    ELEMENT_T* pb = (ELEMENT_T*)b;
    return pa->nums[0] - pb->nums[0];
}
int SearchFirstEle(ELEMENT_T* table, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (table[mid].nums[0] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (left >= size) {
        return -1;
    }
    return table[left].nums[0] >= target ? table[left].index : -1;
}
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize)
{
    int i;
    int temp;
    ELEMENT_T* table = (ELEMENT_T*)calloc(intervalsSize, sizeof(ELEMENT_T));
    int* ans = (int*)calloc(intervalsSize, sizeof(int));
    for (i = 0; i < intervalsSize; i++) {
        memcpy(table[i].nums, intervals[i], 2 * sizeof(int));
        table[i].index = i;
    }
    qsort(table, intervalsSize, sizeof(ELEMENT_T), MyCmp);
    for (i= 0; i < intervalsSize; i++) {
        temp = SearchFirstEle(table, intervalsSize, table[i].nums[1]);
        ans[table[i].index] = temp;
    }
    free(table);
    table = NULL;
    *returnSize = intervalsSize;
    return ans;
}
int main()
{
    int temp[][2] = {
        {1,4},
        {2,3},
        {3,4},
    };
    int **mat = NULL;
    int row = sizeof(temp) / sizeof(temp[0]);
    int col = sizeof(temp[0]) / sizeof(temp[0][0]);
    int i, size;
    mat = (int**)calloc(row, sizeof(int*));
    for (i = 0; i < row; i++) {
        mat[i] = (int*)calloc(col, sizeof(int));
        memcpy(mat[i], temp[i], col * sizeof(int));
    }
    int *res = findRightInterval(mat, row, &col, &size);
    for (i = 0; i < row; i++) {
        printf("%d ", res[i]);
    }
}
