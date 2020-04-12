int MyCmp(const void* a, const void* b) {
    int* pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
// @lc code=start
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int i;
    int* ret = NULL;
    for (i = 0; i < matrixRowSize; i++) {
        ret = (int*)bsearch((int*)&target, (int*)matrix[i], matrixColSize, sizeof(int), MyCmp);
        if (ret != NULL) {
            return true;
        }
    }
    return false;
}
