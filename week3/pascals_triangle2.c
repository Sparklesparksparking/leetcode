/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Helper(int** ret, int row, int size)
{
    if(row > size) {
        return;
    }
    for(int col = 0; col <= row; col++) {
        if (col == 0 || col == row) {
             ret[row][col] = 1;
        } else {
            ret[row][col] = ret[row - 1][col] + ret[row - 1][col - 1];
        }
    }
    Helper(ret, row + 1, size);
}

int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int** ret = (int**)malloc((rowIndex + 1) * sizeof(int*));
    for (int i = 0; i <= rowIndex; i++) {
        ret[i] = (int*)malloc((i + 1) * sizeof(int));
    }
    Helper(ret, 0, rowIndex);
    return ret[rowIndex];
}