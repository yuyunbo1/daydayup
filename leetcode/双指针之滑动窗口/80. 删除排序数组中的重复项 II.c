int removeDuplicates(int* nums, int numsSize)
{
    int left = 0;
    int right = 0;
    int curNum = 0;
    if (numsSize <= 1) {
        return numsSize;
    }
    for (right = 1; right < numsSize; right++) {
        if (nums[right] == nums[left] && curNum < 1) {
            curNum++;
            left++;
            nums[left] = nums[right];
        } else if (nums[left] != nums[right]){
            left++;
            curNum = 0;
            nums[left] = nums[right];
        }
    }
    return left + 1;
}
