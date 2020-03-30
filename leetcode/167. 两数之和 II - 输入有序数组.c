#include<stdio.h>
#include<stdlib.h>
/*
����һ���Ѱ�����������?���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1?����С��?index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0;
    int j = numsSize - 1;
	int* res = (int*)malloc(sizeof(int) * 2);
	memset(res, 0, sizeof(int) * 2);
	while(i < j) {
		if (nums[i] + nums[j] > target) {
			j--;
			continue;
		}
		if (nums[i] + nums[j] < target) {
			i++;
			continue;
		}
		res[0] = i + 1;
		res[1] = j + 1;
		break;
	}
	*returnSize = 2;
	return res;
}

int main()
{
	int nums[] = {3, 3};
	int *res = NULL;
	int size = 0;
	int i;
	res = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 6, &size);
	printf("res[0] %d res[1] %d\n",res[0], res[1]);
}