class Solution {
private:
    int m, n;
    bool found(int pos, int r, int c, vector<vector<char>> &board, string word) {
        if(pos == word.length()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[pos]) return false;
        char tmp = board[r][c];
        board[r][c] = '*';
        bool res = found(pos+1, r, c-1, board, word) || found(pos+1, r, c+1, board, word) ||
        found(pos+1, r-1, c, board, word) || found(pos+1, r+1, c, board, word);
        board[r][c] = tmp;  // restore the value
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
           for(int j = 0; j < n; ++j) {
                if(found(0, i, j, board, word)) {
                    return true;
                }
           }
       }
       return false;
    }
};