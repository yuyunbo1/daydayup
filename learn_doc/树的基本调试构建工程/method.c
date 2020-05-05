
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


/**6.树的层次遍历,空结点补1需要修改*/
int* LevelTraverse(TREENODE_T* root, int* returnSize)
{
    int* res = NULL;
    int res_count = 0;
    int i, levelSize;
    TREENODE_T* headNode = NULL;
    TREENODE_T* tmpNode = NULL;
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
/**7.由先序遍历的数组序列（从BST中来），恢复成BST*/
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
/**8.求树的深度*/
int DfsMaxDepthDownUp(struct TreeNode* root)
{
    int depthLeft;
    int depthRight;
    int max = 0;
    if (root == NULL) {
        return 0;
    }
    depthLeft = DfsMaxDepthDownUp(root->left);
    depthRight = DfsMaxDepthDownUp(root->right);
    return GET_MAX(depthLeft + 1, depthRight + 1);
}
int maxDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    return DfsMaxDepthDownUp(root);
}
/**求树的深度end*/

/**9.递归层次遍历,按层打印，将空节点补齐-1*/
void LevelTraverseDfs(TREENODE_T* root, int** res, int maxLevel, int curLevel, int* resColSize)
{
    if (root == NULL) {
        if (curLevel >= maxLevel) {
            return;
        } else {
            res[curLevel][resColSize[curLevel]++] = -1;
            LevelTraverseDfs(NULL, res, maxLevel, curLevel + 1, resColSize);
            LevelTraverseDfs(NULL, res, maxLevel, curLevel + 1, resColSize);
            return;
        }
    }
    res[curLevel][resColSize[curLevel]++] = root->val;
    LevelTraverseDfs(root->left, res, maxLevel, curLevel + 1, resColSize);
    LevelTraverseDfs(root->right, res, maxLevel, curLevel + 1, resColSize);

}
#define MAX_NODE_NUM 100
int** LevelTraverseDfsDirve(TREENODE_T* root, int* returnSize, int **returnColumnSizes)
{   int i = 0;
    int** res = (int**)calloc(MAX_NODE_NUM, sizeof(int*));
    int* resColSize =(int*)calloc(MAX_NODE_NUM, sizeof(int));
    int maxLevel = 0;
    for (i = 0; i < MAX_NODE_NUM; i++) {
        res[i] = (int*)calloc(MAX_NODE_NUM, sizeof(int));
    }
    /** 先求出最大深度*/
    maxLevel = DfsMaxDepthDownUp(root);
    *returnSize = maxLevel;

    LevelTraverseDfs(root, res, maxLevel, 0, resColSize);
    *returnColumnSizes = resColSize;
    return res;
}
/**递归层次遍历end*/
