class Solution {
private:
    bool isValid(int r, int c, vector<vector<char>> &board, char num) { // pass by reference will save time and space
        for(int i = 0; i < 9; ++i) {
            if(board[r][i] == num) return false;
            if(board[i][c] == num) return false;
        }
        int b_r = (r / 3) * 3, b_c = (c / 3) * 3;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[b_r+i][b_c+j] == num) return false;
            }
        }
        return true;
    }
    bool solver(int r, int c, vector<vector<char>>& board) {
        if(r == 9) return true;
        else if(c == 9) return solver(r+1, 0, board);
        if(board[r][c] == '.') {
            for(char num = '1'; num <= '9'; ++num) {
                if(isValid(r, c, board, num)) {
                    board[r][c] = num;
                    if(solver(r, c+1, board)) return true;
                    board[r][c] = '.';
                }
            }
            return false;
        }
        return solver(r, c+1, board);
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(0, 0, board);
    }
};