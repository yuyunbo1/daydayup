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

/*方法二：
选取起点右上角或左下角进行遍历。
	当matrix[row][col] > target则向左走，换列；
	当matrix[row][col] < target则向下走，换行；
也可以选择左下，为什么不选择左上和右下呢，因为这2个分别为最大最小值，当和target比较时路径不唯一既可以还行也可以换列
*/
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int row = 0;
    int col = matrixColSize - 1;
    while (row < matrixRowSize && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        }
        if (matrix[row][col] > target) {
            col--;
            continue;
        }
        if (matrix[row][col] < target) {
            row++;
        }
    }
    return false;
}
