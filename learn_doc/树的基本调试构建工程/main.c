#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "method.h"
/**test1:从完全二叉树的顺序结构中恢复二叉树*/
void test1()
{
    /**-1表示为空节点*/
    //int vecLevelTraversal[] = {1,2,3,4,5,-1,6,-1,-1,7,8};//OK
    /*
          7
       /    \
    2         8
  /   \        \
 1    6        10
      /       /  \
     3        9   11
       \
       5
      /
     4
    */
    int vecLevelTraversal[] = {7,2,8,1,6,-1,10,-1,-1,3,-1,-1,-1,9,11,-1,-1,-1,-1,
    -1,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4};
    int vecSize = sizeof(vecLevelTraversal) / sizeof(vecLevelTraversal[0]);
    TREENODE_T* tree = NULL;
    int *res = NULL;
    int resSize;
    int i;
    /**从完全二叉树的顺序结构中恢复二叉树*/
    tree = CreateBinaryTreeFromLevelTraverseVec(vecLevelTraversal, 0, vecSize);
    /**先序遍历生成的树*/
    PreOrderDfs(tree);
    printf("\n");
    /**中序遍历*/
    InOrderDfs(tree);
    printf("\n");
    /**后序遍历*/
    PostOrderDfs(tree);
    /**层次遍历*/
    res = LevelTraverse(tree, &resSize);
    printf("\n");
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    /**销毁树之后继续遍历是不行的*/
    DestroyBinaryTree(&tree);
    PreOrderDfs(tree);
    printf("\n");
}
/**test2从BST数组中恢复二叉树,并层次遍历打印出来，以确定长啥样*/
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
void test3()
{
    int treeVec[] = {3,9,20,-1,-1,15,7};
    int treeVecSize = sizeof(treeVec) / sizeof(treeVec[0]);
    TREENODE_T* tree = NULL;
    int *res = NULL;
    int resSize;
    int i;
    tree = CreateBinaryTreeFromLevelTraverseVec(treeVec, 0, treeVecSize);
    res = LevelTraverse(tree, &resSize);
    printf("\ntest3\n");
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
}
int main()
{
    test1();
    //test2();
    //test3();
    return 0;
}


