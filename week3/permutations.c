/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/* 定义当前遍历深度count为全局变量 */
int count;
/* 进行深度优先遍历DFS
 * 参数1：输入数组
 * 参数2：输入数组长度，既数的个数
 * 参数3：当前遍历的深度，一开始为0
 * 参数4：当前走过的路径
 * 参数5：当前结点使用情况，初始都为0未使用
 * 参数6：返回数组
 */
void DFS(int *nums, int numsSize, int depth, int *path, bool *used, int **res) {
    /* 6.1、当前路径已经全部搜索完 */
    if (depth == numsSize) {
        /* 6.1.1、分配返回数组中此次遍历行的列数 */
        res[count] = (int *)malloc(sizeof(int) * numsSize);
        /* 6.1.2、将此行走过的路径赋给res返回数组 */
        memcpy(res[count++], path, sizeof(int) * numsSize);
        /* 6.1.3、返回上一层决策树 */
        return;
    }
    /* 6.2、当前路径未达到树底
     * 遍历搜索列表(既输入数组)，找到下一个结点 
     */
    for (int i = 0; i < numsSize; i++) {
        /* 6.2.1、当前节点已经使用过，跳过 */
        if (used[i] == true) {
            continue;
        }
        /* 6.2.2、当前结点未使用 
         * 将当前结点存入走过的路径path中 
         */
        path[depth] = nums[i];
        /* 6.2.3、标记当前结点已使用过 */
        used[i] = true;
        /* 6.2.4、进入下一层决策树 */
        //depth++;
        DFS(nums, numsSize, depth + 1, path, used, res);
        /* depth表示排列树的深度，回溯时应该回到上一次递归时的结果：
         * 如果depth在dfs之前depth++了，则在每次dfs之后都应depth--，来恢复其状态；
         * 如果depth在下一次传入dfs时直接使用depth+1的结果传入递归，则递归结束后，无需恢复其状态（本来就是原本的状态）。
         */
        //depth--;
        /* 6.2.5、返回上一层决策树之前需要取消当前结点的标记 */
        used[i] = false;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    /* 1、计算返回数组的行数为全排列的种类数：n! */
    (*returnSize) = 1;
    for (int i = 1; i <= numsSize; i++) {
        (*returnSize) *= i;
    }
    /* 2、计算返回数组中每行的列数 */
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    /* 3、定义返回数组 */
    int **res = (int **)malloc(sizeof(int *) * (*returnSize));
    /* 4、定义走过的路径 */
    int *path = (int *)malloc(sizeof(int) * numsSize);
    /* 5、定义结点标记，初始化为0 */
    bool *used = (bool *)calloc(numsSize, sizeof(bool));
    /* 当前遍历深度需要在此赋值
     * 不能在全局定义时赋值，否则会出现内存溢出，就很\U0001f635
     */
    count = 0;
    /* 6、进行深度优先遍历DFS
     * 参数1：输入数组
     * 参数2：输入数组长度，既数的个数
     * 参数3：当前遍历的深度，一开始为0
     * 参数4：当前走过的路径
     * 参数5：当前结点使用情况，初始都为0未使用
     * 参数6：返回数组
     */
    DFS(nums, numsSize, 0, path, used, res);
    /* 7、返回 */
    return res;
}
