int maxDiff = 0;
void Dfs(struct TreeNode* root, int maxNum, int minNum)
{
    if (root == NULL) {
        return 0;
    }
    maxNum = maxNum < root->val ? root->val : maxNum;
    minNum = minNum > root->val ? root->val : minNum;
    maxDiff = maxDiff > abs(maxNum - minNum) ? maxDiff : abs(maxNum - minNum);
    Dfs(root->left, maxNum, minNum);
    Dfs(root->right,maxNum, minNum);
}
int maxAncestorDiff(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    maxDiff = 0;
    Dfs(root, maxNum, minNum);
    return maxDiff;
}
