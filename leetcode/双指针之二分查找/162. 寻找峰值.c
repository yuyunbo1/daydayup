int findPeakElement(int* nums, int numsSize)
{
    int left = 0;
    int right = numsSize - 1;
    int mid;
    // ����right��size �C 1,���Ǳ������ģ�����������mid+1,���������С�ںţ�// �߽粻��.����˳�ѭ��ʵ����
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
