
/*int MyCmp(const void *a, const void* b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return *pa - *pb;
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int i, j;
    int ret;
    int *temp = (int*)calloc(matrixColSize[0] * matrixSize, sizeof(int));
    for (i = 0; i < matrixSize; i++) {
        memcpy(&temp[j + i * matrixColSize[0], matrix[i], matrixColSize[0] * sizeof(int));
    }
    qsort(temp, matrixColSize[0] * matrixSize, sizeof(int), MyCmp);
    ret = temp[k -1];
    free(temp);
    return ret;
}*/
int Count(int** matrix, int matrixSize, int colSize, int value)
{
    int row = 0;
    int col ;
    int count = 0;
    int j;
    for (row = 0; row < matrixSize; row++) {
        if (matrix[row][colSize - 1] <= value) {
            count += colSize;
            continue;
        }
        for (col = 0; col < colSize; col++) {
            if (matrix[row][col] <= value) {
                continue;
            }
            break;
        }
        count += col;
    }
    return count;
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int left = 0;
    int right = 0;
    int mid;
    int count;
    int colSize = matrixColSize[0];
    left = matrix[0][0];
    right = matrix[matrixSize - 1][matrixColSize[0] - 1];
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (left ==right && left == mid) {
            return left;
        }
        count = Count(matrix, matrixSize, matrixColSize[0], mid);
        if (count >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
int main()
{
    int nums[][2] = {
     {1,2},
     {1,3}
    /*{1,  5,  9},
    {10, 11, 13},
    {12, 13, 15},*/
    };
    int ret;
    int i;
    int colSize = sizeof(nums[0]) / sizeof(nums[0][0]);
    int** mat = (int**)calloc(sizeof(nums) / sizeof(nums[0]), sizeof(int*));
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        mat[i] = (int*)calloc(sizeof(nums[0]) / sizeof(nums[0][0]), sizeof(int));
        memcpy(mat[i], nums[i], sizeof(nums[0]) / sizeof(nums[0][0]) * sizeof(int));
    }
    ret = kthSmallest(mat, sizeof(nums) / sizeof(nums[0]), &colSize, 1);
    printf("ret %d\n", ret);

}
