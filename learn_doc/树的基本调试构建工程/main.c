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
    int** resDfs = NULL;
    int* resDfsColSize = (int*)calloc(1, sizeof(int));
    int resDfsReturnSize = 0;
    int resSize;
    int i, j;
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
    /**层次遍历 queue,目前有缺，可以达到调试eetcode的标准，但不满足自己的要求*/
    res = LevelTraverse(tree, &resSize);
    printf("\n");
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    /**层次遍历 dfs*/
    resDfs = LevelTraverseDfsDirve(tree, &resDfsReturnSize, &resDfsColSize);
    for (i = 0; i < resDfsReturnSize; i++) {
        for (j = 0; j < resDfsColSize[i]; j++) {
            printf("%d ", resDfs[i][j]);
        }
        printf("\n");
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
    printf("\ntest2 start\n");
    tree = BuildOneBstTreeByPreorder(preVecFromBst, 0, preVecFromBstSize);
    res = LevelTraverse(tree, &resSize);
    for (i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\ntest2 end\n");
}
int main()
{
    test1();
    test2();
    return 0;
}


