class Solution {
private:
    bool isValid(int r, int c, int n, vector<string> &board) {
        for(int i = 0; i < n; ++i) {
            if(board[i][c] == 'Q') return false;
            if(board[r][i] == 'Q') return false;
        }
        for(int rp = r, cp = c; rp < n && rp >= 0 && cp < n && cp >= 0; rp--, cp++) // need not to check the pos below
            if(board[rp][cp] == 'Q') return false;
        for(int rp = r, cp = c; rp < n && rp >= 0 && cp < n && cp >= 0; rp--, cp--)
            if(board[rp][cp] == 'Q') return false;
        return true;
    }
    void solver(int r, int num, int n, vector<string> &board, vector<vector<string>> &ret) {
        if(num == n) {
            ret.push_back(board);
            return;
        }
        for(int c = 0; c < n; ++c) {    
            if(isValid(r, c, n, board)) {
                board[r][c] = 'Q';
                solver(r+1, num+1, n, board, ret);      // the rest of col. must be invalid
                board[r][c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> board(n, string(n, '.'));
        solver(0, 0, n, board, ret);
        return ret;
    }
};