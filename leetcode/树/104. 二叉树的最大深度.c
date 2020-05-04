#define GET_MAX(x, y) ((x) < (y)) ? (y) : (x)
/*int g_MaxDepth = 0;
void DfsMaxDepthUpDown(struct TreeNode* root, int depth)
{
    // ����Ҷ�ӽڵ�������ֵ
if (root == NULL) {
        g_MaxDepth = GET_MAX(g_MaxDepth, depth);
        return;
}
// �ӽڵ�����Ϊ��ǰ�Ľڵ�����+1
    DfsMaxDepth(root->left, depth + 1);
    DfsMaxDepth(root->right, depth + 1);
}
int maxDepth(struct TreeNode* root)
{
    g_MaxDepth = INT_MIN;
    DfsMaxDepthUpDown (root, 0);
    return g_MaxDepth;
}
*/

int DfsMaxDepthDownUp(struct TreeNode* root)
{
    int depthLeft;
    int depthRight;
    if (root == NULL) {
        return 0;
    }
    depthLeft = DfsMaxDepthDownUp(root->left);
    depthRight = DfsMaxDepthDownUp(root->right);
    return GET_MAX(depthLeft, depthRight) + 1;
}
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return DfsMaxDepthDownUp(root);
}
