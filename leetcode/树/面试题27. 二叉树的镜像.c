struct TreeNode* CreateMirrorTreeDfs(struct TreeNode* root, struct TreeNode* NewRoot)
{
    if (root == NULL) {
        return NULL;
    }
    NewRoot = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
NewRoot->val = root->val;
//ÏÈÓÒºó×ó
    NewRoot->left = CreateMirrorTreeDfs(root->right, NewRoot->left);
    NewRoot->right = CreateMirrorTreeDfs(root->left, NewRoot->right);
    return NewRoot;
}
struct TreeNode* mirrorTree(struct TreeNode* root)
{
    return (struct TreeNode*)CreateMirrorTreeDfs(root, NULL);
}
