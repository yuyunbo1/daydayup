int FindBoudLeft(int* nums, int numsSize, int target)
 {
     int left = 0;
     int right = numsSize - 1;
     int mid;
     if (numsSize == 0) {
        return -1;
     }
     while (left <= right) {
         mid = left + (right - left) / 2;
         if (nums[mid] == target) {
             right = mid - 1; // right不能跳过如6，7，8 找7
             continue;
         }
         if (nums[mid] > target) {
             right = mid - 1;
             continue;
         }
         if (nums[mid] < target) {
             left = mid + 1;
             continue;
         }
     }
     if (left >= numsSize) {
        return -1;
     }

     return nums[left] == target ? left : -1;
 }
 int FindBoudRight(int* nums, int numsSize, int target)
 {
     int left = 0;
     int right = numsSize - 1;
     int mid;
     if (numsSize == 0) {
        return -1;
     }
     while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = left + 1;
            continue;
        }
        if (nums[mid] > target) {
            right = mid - 1;
            continue;
        }
        if (nums[mid] < target) {
            left = mid + 1;
            continue;
        }
     }
     if (right < 0) {
        return -1;
     }
     return nums[left - 1] == target ? left - 1 : -1;

 }
 int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left, right;
    int *res  = (int*)calloc(2, sizeof(int));
    if (numsSize == 1) {
        if (nums[0] == target) {
            res[0] = 0;
            res[1] = 0;
        } else {
            res[0] = -1;
            res[1] = -1;
        }
        *returnSize = 2;
        return res;
    }
    left = FindBoudLeft(nums, numsSize, target);
    right = FindBoudRight(nums, numsSize, target);
    *returnSize = 2;
    res[0] = left;
    res[1] = right;
    return res;

}
