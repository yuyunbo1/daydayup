int MyCmp(const void* a, const void* b)
{
    int* pa = (int*)a;
    int* pb = (int*)b;
    return *pa - *pb;
}
int IsEnough(int* nums, int numsSize, int threshold, int div)
{
    int i;
    int cur = 0;
    for (i = 0; i < numsSize; i++) {
        cur += (nums[i] / div);
        cur += (nums[i] % div == 0 ? 0 : 1);
        if (cur > threshold) {
            return 0;
        }
    }
    return 1;
}
int smallestDivisor(int* nums, int numsSize, int threshold)
{
    int left = 1;
    int right ,mid;
    int i, temp;
    qsort(nums, numsSize, sizeof(int), MyCmp);
    right = nums[numsSize - 1];

    while (left <= right) {
        mid = left + (right - left) / 2;
        temp = IsEnough(nums, numsSize, threshold, mid);
        if (temp == 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (right < 1) {
        temp = IsEnough(nums, numsSize, threshold, left);
        return temp == 1 ? left : 0;
    }
    temp = IsEnough(nums, numsSize, threshold, left);
    return temp == 1 ? left : 0;

}
