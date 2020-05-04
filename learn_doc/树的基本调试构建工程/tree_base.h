#ifndef __TREE_BASE_H_
#define __TREE_BASE_H_

#define GET_MAX(x, y) ((x) < (y)) ? (y) : (x)

typedef struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
}TREENODE_T;

#endif //__TREE_BASE_H_
