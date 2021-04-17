/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void Helper(int** ret, int row, int size)
{
    if (row >= size) {
        return;
    }
    for(int col = 0; col <= row; col++) {
        if(col == 0 || (row == col)) {
            ret[row][col] = 1;
        } else {
            ret[row][col] = ret[row - 1][col - 1] + ret[row - 1][col];
        }
    }
    
    Helper(ret, row + 1, size);
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    if (numRows == NULL) {
        return NULL;
    }
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
    }
    int** ret = (int**)malloc(numRows * sizeof(int*));
    for (int i = 0; i < numRows; i++) {
        ret[i] = (int*)calloc(i + 1, sizeof(int));
    }
    Helper(ret, 0, numRows);
    return ret;
} 