#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define bool int
int my_cmp(const void* a, const void* b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return *pa - *pb;
}

int dfs(int* nums, int numsSize, int target, int* flag, int start, int index, int k)
{
	int i = 0;
	if (k == 0) 
		return true;
	for (i = start; i < numsSize && (nums[i] + index <= target); ++i) {
		if (flag[i] == 0 ) {
			flag[i] = 1;
			if (nums[i] + index == target) {
				if (dfs(nums, numsSize, target, flag, 0, 0, k - 1))
					return true;
			}
			else if (dfs(nums, numsSize, target, flag, i + 1,nums[i] + index, k))
				return true;
			flag[i] = 0;
		}
	}
	return false;
}
bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
	int sum = 0;
	int i, target;
	int flag[40] ={0};
	int max = -1;
	for (i = 0; i <numsSize; i++) {
		sum += nums[i];
		if (max < nums[i]) {
			max = nums[i];
		}
	}
	if (sum % k != 0) {
		return false;
	}
	target = sum / k;
	if ( max > target) {
		return false;
	}
	qsort(nums, numsSize, sizeof(int), my_cmp);
	return dfs(nums, numsSize, target,flag,0, 0, k);
}
int main()
{
	int nums0[]= {10,10,10,7,7,7,7,7,7,6,6,6};//3
	int nums1[]= {4, 3, 2, 3, 5, 2, 1};//4
	int res0 = 0,res1 = 0;
	int i;
	res0 = canPartitionKSubsets(nums0, sizeof(nums0) / sizeof(int), 3);
	res1 = canPartitionKSubsets(nums1, sizeof(nums1) / sizeof(int), 4);
	printf("res0 = %d,res1 = %d\n",res0, res1);
}
/*
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        if(sum % k != 0) return false;
        sort(nums.begin(),nums.end());
        target = sum / k;
        vector<int> flag(nums.size(),0);
        return dfs(nums, flag, 0, 0, k);
        
    }
    bool dfs(vector<int>& nums, vector<int> flag, int start, int index, int k){
        if(k == 0) return true;
        for(int i = start; i < nums.size() && nums[i] + index <= target; ++i){
            if(flag[i] == 0){
                flag[i] = 1;
                if((nums[i] + index) == target)
                    return dfs(nums, flag, 0, 0, k -1);
                else if(dfs(nums, flag, i + 1, nums[i] + index, k))
                    return true;
                flag[i] = 0;
            }
        }
        return false;
    }
    int target = 0;
};
*/