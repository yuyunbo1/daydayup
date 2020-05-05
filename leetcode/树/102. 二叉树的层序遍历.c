#define MAX_NODE_NUM 100
#define GET_MAX(x, y) ((x) > (y)) ? (x) : (y)
int g_level;
void LevelTraverseDfs(TREENODE_T* root, int** res, int level, int* resColSize)
{
    if (root == NULL) {
        g_level = GET_MAX(g_level, level);
        return;
    }
    res[level][resColSize[level]++] = root->val;
    LevelTraverseDfs(root->left, res, level + 1, resColSize);
    LevelTraverseDfs(root->right, res, level + 1, resColSize);

}
int** levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int **res = NULL;
    int* resColSize = NULL;
    int i;
    g_level = 0;
    resColSize = (int*)calloc(MAX_NODE_NUM, sizeof(int));
    res = (int**)calloc(MAX_NODE_NUM, sizeof(int*));
    for (i = 0; i < MAX_NODE_NUM; i++) {
        res[i] = (int*)calloc(MAX_NODE_NUM, sizeof(int));
    }

    LevelTraverseDfs(root, res, level, resColSize);
    *returnColumnSizes = resColSize;
    *returnSize = g_level;
    return res;
}
