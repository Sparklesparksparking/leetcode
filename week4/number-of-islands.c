int step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void Helper(char** grid, int gridSize, int* gridColSize, int m, int n)
{
    if (grid[m][n] != '1'){
        return;
    }
    grid[m][n] = 0;
    for (int i = 0; i < 4; i++) {
        if ((m + step[i][0] < 0) || (m + step[i][0] >= gridSize) ||
        (n + step[i][1] < 0) || (n + step[i][1] >= gridColSize[0])) {
            continue;
        }
        Helper(grid, gridSize, gridColSize, m + step[i][0], n + step[i][1]);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                cnt++;
                Helper(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return cnt;
}