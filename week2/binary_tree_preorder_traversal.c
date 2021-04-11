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
void preorder(struct TreeNode* root, int* ret, int* retSize)
{
    if (root == NULL) {
        return;
    }
    ret[(*retSize)++] = root->val;
    preorder(root->left, ret, retSize);
    preorder(root->right, ret, retSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* ret = (int*)malloc(100 * sizeof(int));
    preorder(root, ret, returnSize);
    return ret;
}