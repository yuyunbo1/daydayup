int MyCmp(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return *pb - *pa;
}
int dominantIndex(int* nums, int numsSize){
	int *temp = NULL;
	int i;

	if (numsSize == 1) {
		return 0;
	}
    temp = (int*)malloc(sizeof(int) * numsSize);
	memcpy(temp, nums, sizeof(int) * numsSize);
	qsort(temp, numsSize, sizeof(int), MyCmp);
	if (temp[0] < (temp[1] << 1)) {
        free(temp);
		return -1;
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] == temp[0]) {
            free(temp);
			return i;
		}
	}
	return 0;
}