#ifndef __METHOD_H__
#define __METHOD_H__

/**1.�Ӳ�α����������У���ȫ���������ָ�ԭ��������ԭ����һ������ȫ������*/
TREENODE_T* CreateBinaryTreeFromLevelTraverseVec(int* vec, int start, int vecSize);
/**2.���ٶ���������ʵ�Ǻ�������*/
void DestroyBinaryTree(TREENODE_T** root);
/**3.�������*/
void PreOrderDfs(TREENODE_T* root);
/**4.�������*/
void InOrderDfs(TREENODE_T* root);
/**5.�������*/
void PostOrderDfs(TREENODE_T* root);
/**6.���Ĳ�α���*/
int* LevelTraverse(TREENODE_T* root, int* returnSize);
/**7.������������������У���BST���������ָ���BST*/
struct TreeNode* BuildOneBstTreeByPreorder(int* preOrder, int preLeft, int preRight);
#endif // __METHOD_H__
