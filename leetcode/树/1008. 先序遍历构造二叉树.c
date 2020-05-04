struct TreeNode* BuildOneBstTreeByPreorder(int* preOrder, int preLeft, int preRight)
{
    struct TreeNode* root = NULL;
    int index = 0;
    if (preLeft >= preRight) {
        return NULL;
    }
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = preOrder[preLeft];
    /**�ҵ���һ���ȸ�����±꣬Ϊ�˷ָ��Ȼʣ��Ĳ����ϸ�����ģ���Ȼ�������ö��ֲ��ҵķ���Ѱ�����index*/
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
