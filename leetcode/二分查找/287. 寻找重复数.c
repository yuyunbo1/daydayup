int findDuplicate(int* nums, int numsSize)
{
    int left = 1;
    int right = numsSize - 1;
    int mid;
    int i;
    int count = 0;
    while (left <= right) {
        mid  = left + (right - left) / 2;
        count = 0;
        for (i = 0; i < numsSize; i++) {
            if (nums[i] < mid) {
                count++;
            }
        }
        if (count >= mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left - 1;  //使用mid是不行的，使用right也可以
}
