#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)
 int MyCmp(const void* a, const void* b)
 {
     int* pa = (int*)a;
     int* pb = (int*)b;
     return *pa > *pb ? 1 : -1;
 }
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int size = GET_MAX(nums1Size, nums2Size);
    int* res = (int*)calloc(size, sizeof(int));
    int resIndex = 0;
    int i = 0;
    int j = 0;

    qsort(nums1, nums1Size, sizeof(int), MyCmp);
    qsort(nums2, nums2Size, sizeof(int), MyCmp);
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            res[resIndex] = nums1[i];
            resIndex++;
            i++;
            j++;
            continue;
        }
		// 求相交的精髓
        if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    *returnSize = resIndex;
    return res;
}
