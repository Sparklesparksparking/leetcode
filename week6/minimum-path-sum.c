int Min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    int** dp = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; i++) {
        dp[i] = (int*)calloc(gridColSize[0], sizeof(int));
    }
    dp[0][0] = grid[0][0];

    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < gridColSize[0]; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i  = 1; i < gridSize; i++) {
        for (int j = 1; j < gridColSize[0]; j++) {
            dp[i][j] = grid[i][j] + Min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[gridSize - 1][gridColSize[0] - 1];
}