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
    /**���������*/
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = preOrder[preLeft];
    /**Ѱ�Ҹ��ڵ���order�е�λ��,��ͼ�ҵ��ҳ���ǰ���ڵ�����������������Լ���������������*/
    for (iRoot = inLeft; iRoot < inRight; iRoot++) {
        if (inOrder[iRoot] == root->val) {
            break;
        }
    }
    /**����iRoot�з�����,�����ڲ�����*/
    lenLeft = iRoot - inLeft;
    /**������ǰ����������м����ݹ鹹������*/
    root->left = BuildreeByPreAndInorder(preOrder, preLeft + 1, preLeft + 1 + lenLeft,
                                         inOrder, inLeft, iRoot);/**iRootû�м�1����Ϊ������*/
    /**������ǰ����������м����ݹ鹹������*/
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
