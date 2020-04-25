int findPeakElement(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    // 由于right是size – 1,本是闭区间查的，但是由于有mid+1,因此这里用小于号，// 边界不查.因此退出循环实际上
    while (left < right) {
        mid = left + (right - left) / 2;
        //printf("%d %d %d\n",left, right, mid);
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
    }
    return left;
}
