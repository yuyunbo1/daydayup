void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int numIndex1 = m - 1;
    int numIndex2 = n - 1;
    int tmp = m + n - 1;
    while (numIndex1 >= 0 && numIndex2 >= 0) {
        if (nums1[numIndex1] >= nums2[numIndex2]) {
            nums1[tmp] = nums1[numIndex1];
            tmp--;
            numIndex1--;
        } else {
            nums1[tmp] = nums2[numIndex2];
            tmp--;
            numIndex2--;
        }
    }
    while (numIndex2 >= 0) {
        nums1[tmp] = nums2[numIndex2];
        tmp--;
        numIndex2--;
    }
}
