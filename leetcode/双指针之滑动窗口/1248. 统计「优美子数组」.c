int numberOfSubarrays(int* nums, int numsSize, int k)
{
    int right;
    int oddStartIndex = 0;
    int* oddIndexs = (int*)calloc(numsSize + 2, sizeof(int));
    int i = 0, leftNum, rightNum;
    int res = 0;
    oddIndexs[oddStartIndex] = -1;
    oddStartIndex++;
    // oddIndexs数组用于记录原数组中元素为奇数的下标
    for (right = 0; right < numsSize; right++) {
        if (nums[right] & 0x1 == 1) {
            oddIndexs[oddStartIndex] = right;
            oddStartIndex++;
        }
    }
    oddIndexs[oddStartIndex] = right;
    // 计算(maxRgiht - minRight) * (maxLeft - minLeft)
    for (i = 0; i < oddStartIndex - k ; i++) {
        rightNum = oddIndexs[i + k + 1] - oddIndexs[i + k];
        leftNum = oddIndexs[i + 1] - oddIndexs[i];
        res += leftNum * rightNum;
    }
    return res;
}
