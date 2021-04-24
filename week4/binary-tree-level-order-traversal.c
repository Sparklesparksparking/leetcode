/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #define MAX_SIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    
    struct TreeNode* queue[MAX_SIZE];
    int** res = (int**)malloc(sizeof(int*) * MAX_SIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);

    int head = 0;
    int rear = 0;
    queue[rear++] = root;

    while (head != rear) {
        int preRear = rear;
        res[*returnSize] = (int*)malloc(sizeof(int) * (preRear - head));
        int cnt = 0;
        while (head < preRear) {
            struct TreeNode* p = queue[head];
            res[*returnSize][cnt++] = p->val;
            if (p->left) {
                queue[rear++] = p->left;
            }
            if (p->right) {
                queue[rear++] = p->right;
            }
            head++;
        }
        (*returnColumnSizes)[*returnSize] = cnt;
        (*returnSize)++;
    }
    return res;
}