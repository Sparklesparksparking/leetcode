int Min(int a, int b, int c) 
{
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int Max(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    if (matrix == NULL || matrixSize < 1 || matrixColSize[0] < 1) {
        return 0;
    }
    int max = 0;
    int** dp = (int**)malloc((matrixSize + 1) * sizeof(int*));
    for (int i = 0; i < matrixSize + 1; i++) {
        dp[i] = (int*)calloc((matrixColSize[0] + 1), sizeof(int));
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (matrix[i][j] == '1') {
                dp[i + 1][j + 1] = Min(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1;
                max = Max(max, dp[i + 1][j + 1]);
            }
        }
    }
    return max * max;
}