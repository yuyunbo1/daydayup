#define MAX 2000
int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes)
{
    int** res = (int**)calloc(MAX, sizeof(int*));
    int* colSize = (int*)calloc(MAX, sizeof(int));
    int i = 0;
    int j = 0;
    int left, right;
    int resIndex = 0;

    if (BSize == 0) {
        *returnSize  = 0;
        return res;
    }
    for (i = 0; i < MAX; i++) {
        res[i] = (int*)calloc(2, sizeof(int));
        colSize[i] = 2;
    }
    i = 0;
    while (i < ASize && j < BSize) {
        left = (A[i][0] > B[j][0]) ? A[i][0] : B[j][0];
        right = (A[i][1] > B[j][1]) ? B[j][1] : A[i][1];
        if (left <= right) {
            res[resIndex][0] = left;
            res[resIndex][1] = right;
            resIndex++;
        }
        if (A[i][1] > B[j][1]) {
            j++;
        } else {
            i++;
        }
    }
    *returnSize = resIndex;
    *returnColumnSizes = colSize;
    return res;
}
