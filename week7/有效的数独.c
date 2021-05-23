bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int col[9][9] = {0};
    int row[9][9] = {0};
    int box[9][9] = {0};
    int num;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.')  {
                num = board[i][j] - '1';
                if ((col[i][num]) || (row[j][num]) || (box[(i / 3) * 3 + j / 3][num])) {
                    return false;
                } else {
                    col[i][num] = 1;
                    row[j][num] = 1;
                    box[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        }
    }
    return true;
}