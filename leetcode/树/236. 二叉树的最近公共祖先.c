
/**
如果两个数分别在一个节点的左右子树中，那么本节点就是最近的公共祖先
如果同时在一边 那么继续递归
*/
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    struct TreeNode *left, *right;
    // 表示找完了
    if (root == NULL || root == q || root == p) {
        return root;
    }
    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);
    if (left != NULL && right != NULL) {
        return root;
    }
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    return NULL;
}
