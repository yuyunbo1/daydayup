#include <stdio.h>
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

struct TreeNode* BuildreeByPreAndInorder(int* preOrder, int preLeft, int preRight,
                                         int* inOrder, int inLeft, int inRight)
{
    int iRoot;
    int lenLeft;
    int lenRight;
    struct TreeNode* root = NULL;
    if (preLeft >= preRight || inLeft >= inRight) {
        return NULL;
    }
    /**创建根结点*/
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = preOrder[preLeft];
    /**寻找根节点在order中的位置,试图找到找出当前根节点的左树的中序序列以及右树的中序序列*/
    for (iRoot = inLeft; iRoot < inRight; iRoot++) {
        if (inOrder[iRoot] == root->val) {
            break;
        }
    }
    /**根据iRoot切分序列,体现在参数上*/
    lenLeft = iRoot - inLeft;
    /**左树的前序和中序序列继续递归构造左树*/
    root->left = BuildreeByPreAndInorder(preOrder, preLeft + 1, preLeft + 1 + lenLeft,
                                         inOrder, inLeft, iRoot);/**iRoot没有减1是因为开区间*/
    /**右树的前序和中序序列继续递归构造右树*/
    root->right = BuildreeByPreAndInorder(preOrder, preLeft + 1 + lenLeft, preRight,
                                          inOrder, iRoot + 1, inRight);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* root = NULL;
    root = BuildreeByPreAndInorder(preorder, 0, preorderSize,
                                   inorder, 0, inorderSize);
    return root;
}
int main()
{
    int preOrder[] = {3,9,20,15,7};
    int inOrder[] = {9,3,15,20,7};
    int preSize = sizeof(preOrder) / sizeof(preOrder[0]);
    int inSize = sizeof(inOrder) / sizeof(inOrder[0]);
    struct TreeNode* root = buildTree(preOrder, preSize, inOrder, inSize);

}
