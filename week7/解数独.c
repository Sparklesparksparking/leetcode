    bool col[9][9];
    bool row[9][9];
    bool box[3][3][9];
    int* spaces[81];
    int spaceSize = 0;
    int valid;

int Dfs(char** board, int pos)
{
    if (pos == spaceSize) {
        valid = true;
        return;
    }
    int i = spaces[pos][0];
    int j = spaces[pos][1];
    for (int k = 0; k < 9 && !valid; k++) {
        if (col[i][k] == false && row[j][k] == false && box[i/3][j/3][k] == false) {
            col[i][k] = true;
            row[j][k] = true;
            box[i/3][j/3][k] = true;
            board[i][j] = k + '0' + 1;
            Dfs(board, pos + 1);
            col[i][k] = false;
            row[j][k] = false;
            box[i/3][j/3][k] = false;
        }
    }

}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    memset(col, false, sizeof(col));
    memset(row, false, sizeof(row));
    memset(box, false, sizeof(box));
    valid = false;
    spaceSize = 0;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == '.') {
                spaces[spaceSize] = malloc(sizeof(int) * 2);
                spaces[spaceSize][0] = i;
                spaces[spaceSize][1] = j;
                spaceSize++;
            } else {
                int k = board[i][j] - '0' - 1;
                col[i][k] = true;
                row[j][k] = true;
                box[i/3][j/3][k] = true;    
            }
        }
    }
    Dfs(board, 0);
}