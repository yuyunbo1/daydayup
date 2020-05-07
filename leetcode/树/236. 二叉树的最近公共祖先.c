
/**
����������ֱ���һ���ڵ�����������У���ô���ڵ��������Ĺ�������
���ͬʱ��һ�� ��ô�����ݹ�
*/
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    struct TreeNode *left, *right;
    // ��ʾ������
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
