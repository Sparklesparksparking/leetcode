bool Check(int* visited, int row, int col)
{
    for (int i = 0; i < row; i++) {
        if ((col == visited[i]) || (row + col == i + visited[i]) || (row - col == i - visited[i])) {
            return false;
        }
    }
    return true;
}

void BackTrack(int n, int row, int* visited, char*** result, int* returnSize)
{
    if (row == n) {
        result[*returnSize] = (char**)malloc(n * sizeof(char**));
        for (int i = 0; i < n; i++) {
            result[*returnSize][i] = (char*)calloc(n + 1, sizeof(char));
            memset(result[*returnSize][i], '.', n);
            result[*returnSize][i][visited[i]] = 'Q';
        }
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (Check(visited, row, i) == false) {
            continue;
        }
        visited[row] = i;
        BackTrack(n, row + 1, visited, result, returnSize);
        visited[row] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int* visited = (int*)calloc(n, sizeof(int));
    char*** result = (char***)malloc(n * n * n * sizeof(char**));
    //回溯算法
    BackTrack(n, 0, visited, result, returnSize);
    *returnColumnSizes = (int*)malloc(*returnSize *sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}

