/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #define GET_MAX(x, y) ((x) < (y)) ? (y) : (x)
#define GET_MIN(x, y) ((x) > (y)) ? (y) : (x)
struct TreeNode* lowestCommonAncestorDfs(struct TreeNode* root, int pVal, int qVal)
{
    int x = GET_MAX(pVal, qVal);
    int y = GET_MIN(pVal, qVal);
    if (root->val >= y && root->val <= x) {
        return root;
    } else if (root->val < y) {
        return lowestCommonAncestorDfs(root->right, pVal, qVal);
    }
    return lowestCommonAncestorDfs(root->left, pVal, qVal);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL) {
        return q;
    } else if (q == NULL) {
        return q;
    }
    return lowestCommonAncestorDfs(root, p->val, q->val);
}
