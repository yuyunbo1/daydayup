#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

/**1.从层次遍历出的序列（完全二叉树）恢复原来的树，原来不一定是完全二叉树*/
TREENODE_T* CreateBinaryTreeFromLevelTraverseVec(int* vec, int start, int vecSize)
{
    TREENODE_T* root = NULL;
    /**节点用完了，就不用继续了*/
    if (start >= vecSize) {
        return NULL;
    }
    /**如果是空节点的话也不进行构造*/
    if (vec[start] == -1) {
        return NULL;
    }

    root = (TREENODE_T*)calloc(1, sizeof(TREENODE_T));
    root->val = vec[start];
    root->left = CreateBinaryTreeFromLevelTraverseVec(vec, start * 2 + 1,vecSize);
    root->right = CreateBinaryTreeFromLevelTraverseVec(vec, start * 2 + 2,vecSize);
    return root;
}
/**2.销毁二叉树，其实是后续遍历*/
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
/**3.先序遍历*/
void PreOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    PreOrderDfs(root->left);
    PreOrderDfs(root->right);
}
/**4.中序遍历*/
void InOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    InOrderDfs(root->left);
    printf("%d ", root->val);
    InOrderDfs(root->right);
}
/**5.后序遍历*/
void PostOrderDfs(TREENODE_T* root)
{
    if (root == NULL) {
        return;
    }
    PostOrderDfs(root->left);
    PostOrderDfs(root->right);
    printf("%d ", root->val);
}
/**6.树的层次遍历*/
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
                QueuePush(&queue, headNode->left);
                QueuePush(&queue, headNode->right);
            }
        }
    }
    *returnSize = res_count;
    return res;
}
int main()
{   /**-1表示为空节点*/
    int vecLevelTraversal[] = {1,2,3,4,5,-1,6,-1,-1,7,8,-1,-1};
    int vecSize = sizeof(vecLevelTraversal) / sizeof(vecLevelTraversal[0]);
    TREENODE_T* tree = NULL;
    int *res = NULL;
    int resSize;
    int i;
    tree = CreateBinaryTreeFromLevelTraverseVec(vecLevelTraversal, 0, vecSize);
    PreOrderDfs(tree);
    printf("\n");
    InOrderDfs(tree);
    printf("\n");
    PostOrderDfs(tree);

    res = LevelTraverse(tree, &resSize);
    printf("\n");
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }

    /**销毁树之后继续遍历是不行的*/
    DestroyBinaryTree(&tree);
    PreOrderDfs(tree);
    printf("\n");
    return 0;
}

