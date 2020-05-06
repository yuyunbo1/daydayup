struct TreeNode* sortedArrayToBSTDfs(int* nums, int numsSize, int startIndex, int endIndex)
{
    int mid;
    struct TreeNode* root = NULL;

    mid = startIndex + (endIndex - startIndex) / 2;
    if (mid < 0 || mid > endIndex || mid == numsSize) {
        return NULL;
    }
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sortedArrayToBSTDfs(nums, numsSize, startIndex, mid - 1);
    root->right = sortedArrayToBSTDfs(nums, numsSize, mid + 1, endIndex);
    return root;

}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return sortedArrayToBSTDfs(nums, numsSize, 0, numsSize);
}
