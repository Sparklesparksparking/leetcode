int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void Dfs(char** grid, int gridSize, int* gridColSize, int x, int y)
{
    grid[x][y] = '0';
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
        Dfs(grid, gridSize, gridColSize, x - 1, y);
        };
    if (x + 1 < gridSize && grid[x + 1][y] == '1') {
        Dfs(grid, gridSize, gridColSize, x + 1, y);
        };
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
        Dfs(grid, gridSize, gridColSize, x, y - 1);
        };
    if (y + 1 < gridColSize[0] && grid[x][y + 1] == '1') {
        Dfs(grid, gridSize, gridColSize, x, y + 1);
        };        
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (grid == NULL || gridSize <= 0 || gridColSize[0] <= 0) {
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                ret++;
                Dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return ret;
}
