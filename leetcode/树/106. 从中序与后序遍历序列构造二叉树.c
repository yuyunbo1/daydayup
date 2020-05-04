#include<stdlib.h>
/**
������� inorder = [9,3,15,20,7]    �����
������� postorder = [9,15,7,20,3]  ���Ҹ�
*/
struct TreeNode* BuildTreeByPostAndInorder(int* postOrder, int postLeft, int postRight,
                                           int* inOrder, int inLeft, int inRight)
{
    struct TreeNode* root = NULL;
    int iRoot;
    int lenLeft;
    if (postLeft >= postRight || inLeft >= inRight) {
        return NULL;
    }
    root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    root->val = postOrder[postRight - 1];

    /**�����������������Ѱ�Ҹ���λ�ã���һ����ηָ�����*/
    for (iRoot = inLeft; iRoot < inRight; iRoot++) {
        if (inOrder[iRoot] == root->val) {
            break;
        }
    }
    lenLeft = iRoot - inLeft;
    /**����������*/
    root->left = BuildTreeByPostAndInorder(postOrder, postLeft, postLeft + lenLeft,
                                           inOrder, inLeft, iRoot);
    /**����������*/
    root->right = BuildTreeByPostAndInorder(postOrder, postLeft + lenLeft, postRight - 1,
                                            inOrder, iRoot + 1, inRight);
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    struct TreeNode* root = NULL;
    root = BuildTreeByPostAndInorder(postorder, 0, postorderSize,
                                     inorder, 0, inorderSize);
    return root;
}
int main()
{

}
