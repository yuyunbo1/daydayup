int g_ans = 0;
void rangeSumBSTDfs(struct TreeNode* root, int L, int R)
{
    if (root == NULL) {
        return;
    }
    if (root->val >= L && root->val <= R) {
        g_ans += root->val;
        rangeSumBSTDfs(root->left, L, R);
        rangeSumBSTDfs(root->right, L, R);
    }
    if (root->val < L) {
        rangeSumBSTDfs(root->right, L, R);
    } else if (root->val > R){
        rangeSumBSTDfs(root->left, L, R);
    }

}
int rangeSumBST(struct TreeNode* root, int L, int R){
    g_ans = 0;
    rangeSumBSTDfs(root, L, R);
    return g_ans;
}
