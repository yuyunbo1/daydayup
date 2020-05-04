#ifndef __METHOD_H__
#define __METHOD_H__

/**1.从层次遍历出的序列（完全二叉树）恢复原来的树，原来不一定是完全二叉树*/
TREENODE_T* CreateBinaryTreeFromLevelTraverseVec(int* vec, int start, int vecSize);
/**2.销毁二叉树，其实是后续遍历*/
void DestroyBinaryTree(TREENODE_T** root);
/**3.先序遍历*/
void PreOrderDfs(TREENODE_T* root);
/**4.中序遍历*/
void InOrderDfs(TREENODE_T* root);
/**5.后序遍历*/
void PostOrderDfs(TREENODE_T* root);
/**6.树的层次遍历*/
int* LevelTraverse(TREENODE_T* root, int* returnSize);
/**7.由先序遍历的数组序列（从BST中来），恢复成BST*/
struct TreeNode* BuildOneBstTreeByPreorder(int* preOrder, int preLeft, int preRight);
#endif // __METHOD_H__
