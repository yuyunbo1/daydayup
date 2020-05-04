
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

/**1.�Ӳ�α����������У���ȫ���������ָ�ԭ��������ԭ����һ������ȫ������*/
TREENODE_T* CreateBinaryTreeFromLevelTraverseVec(int* vec, int start, int vecSize)
{
    TREENODE_T* root = NULL;
    /**�ڵ������ˣ��Ͳ��ü�����*/
    if (start >= vecSize) {
        return NULL;
    }
    /**����ǿսڵ�Ļ�Ҳ�����й���*/
    if (vec[start] == -1) {
        return NULL;
    }

    root = (TREENODE_T*)calloc(1, sizeof(TREENODE_T));
    root->val = vec[start];
    root->left = CreateBinaryTreeFromLevelTraverseVec(vec, start * 2 + 1,vecSize);
    root->right = CreateBinaryTreeFromLevelTraverseVec(vec, start * 2 + 2,vecSize);
    return root;
}
/**2.���ٶ���������ʵ�Ǻ�������*/
void DestroyBinaryTree(TREENODE_T** root)
{
    if (*root == NULL) {
        return;
    }
    DestroyBinaryTree(&((*root)->left));
    DestroyBinaryTree(&((*root)->right));
    free(*root);
    *root = NULL;
}
/**3.�������*/
void PreOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    PreOrderDfs(root->left);
    PreOrderDfs(root->right);
}
/**4.�������*/
void InOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    InOrderDfs(root->left);
    printf("%d ", root->val);
    InOrderDfs(root->right);
}
/**5.�������*/
void PostOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    PostOrderDfs(root->left);
    PostOrderDfs(root->right);
    printf("%d ", root->val);
}
/**6.���Ĳ�α���*/
int* LevelTraverse(TREENODE_T* root, int* returnSize)
{
    int* res = NULL;
    int res_count = 0;
    int i, levelSize;
    TREENODE_T* headNode = NULL;
    QUEUE_T queue = {0};
    QueueReInit(&queue);
    QueuePush(&queue, root);
    res = (int*)calloc(QUEUE_MAX, sizeof(int));

    while (QueueIsEmpty(&queue) != 1) {
        levelSize = QueueSize(&queue);
        for (i = 0;i < levelSize; i++) {
            headNode = QueuePop(&queue);
            if (headNode == NULL) {
                res[res_count++] = -1;
            } else {
                res[res_count++] = headNode->val;
                if (headNode->left == NULL && headNode->right == NULL) {
                    continue;
                }
                QueuePush(&queue, headNode->left);
                QueuePush(&queue, headNode->right);
            }
        }
    }
    *returnSize = res_count;
    return res;
}
/**7.������������������У���BST���������ָ���BST*/
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


