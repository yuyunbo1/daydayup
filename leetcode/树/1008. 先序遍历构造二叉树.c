struct TreeNode* BuildOneBstTreeByPreorder(int* preOrder, int preLeft, int preRight)
{
    struct TreeNode* root = NULL;
    int index = 0;
    if (preLeft >= preRight) {
        return NULL;
    }
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = preOrder[preLeft];
    /**找到第一个比根大的下标，为了分割。虽然剩余的不是严格排序的，仍然可以利用二分查找的方法寻找这个index*/
    for (index = preLeft + 1; index < preRight; index++) {
        if (preOrder[index] > root->val) {
            break;
        }
    }

    root->left = BuildOneBstTreeByPreorder(preOrder, preLeft + 1, index);
    root->right = BuildOneBstTreeByPreorder(preOrder, index, preRight);
    return root;
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{
    struct TreeNode* root = NULL;
    root = BuildOneBstTreeByPreorder(preorder, 0, preorderSize);
    return root;
}
