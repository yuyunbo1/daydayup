
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 int Dfs(struct TreeNode* root)
 {
    // ÇÀ
    int doIt, notDoIt;
    if (root == NULL) {
        return 0;
    }
    doIt = root->val +
        (root->left == NULL ? 0 : (Dfs(root->left->left) + Dfs(root->left->right))) +
        (root->right == NULL ? 0 : (Dfs(root->right->left) + Dfs(root->right->right)));
    notDoIt = Dfs(root->left) + Dfs(root->right);

    return (doIt > notDoIt ? doIt : notDoIt);

 }

int rob(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return Dfs(root);
}
