#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "method.h"
/**test1:����ȫ��������˳��ṹ�лָ�������*/
void test1()
{
    /**-1��ʾΪ�սڵ�*/
    int vecLevelTraversal[] = {1,2,3,4,5,-1,6,-1,-1,7,8,-1,-1};
    int vecSize = sizeof(vecLevelTraversal) / sizeof(vecLevelTraversal[0]);
    TREENODE_T* tree = NULL;
    int *res = NULL;
    int resSize;
    int i;
    /**����ȫ��������˳��ṹ�лָ�������*/
    tree = CreateBinaryTreeFromLevelTraverseVec(vecLevelTraversal, 0, vecSize);
    /**����������ɵ���*/
    PreOrderDfs(tree);
    printf("\n");
    /**�������*/
    InOrderDfs(tree);
    printf("\n");
    /**�������*/
    PostOrderDfs(tree);
    /**��α���*/
    res = LevelTraverse(tree, &resSize);
    printf("\n");
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    /**������֮����������ǲ��е�*/
    DestroyBinaryTree(&tree);
    PreOrderDfs(tree);
    printf("\n");
}
/**test2��BST�����лָ�������,����α�����ӡ��������ȷ����ɶ��*/
void test2()
{
    int preVecFromBst[] = {8,5,1,7,10,12};
    int preVecFromBstSize = sizeof(preVecFromBst) / sizeof(preVecFromBst[0]);
    TREENODE_T* tree = NULL;
    int *res = NULL;
    int resSize;
    int i;
    tree = BuildOneBstTreeByPreorder(preVecFromBst, 0, preVecFromBstSize);
    res = LevelTraverse(tree, &resSize);
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
}
int main()
{
    test1();
    test2();
    return 0;
}


