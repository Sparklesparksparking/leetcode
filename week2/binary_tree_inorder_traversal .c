/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* ret, int* retSize)
{
    if (root == NULL) {
        return;
    }
    inorder(root->left, ret, retSize);
    ret[(*retSize)++] = root->val;
    inorder(root->right, ret, retSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    inorder(root, ret, returnSize);
    return ret;
}