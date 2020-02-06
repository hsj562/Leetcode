class Solution {
private:
    void dfs(const int rsz, const int csz, int i, int j, bool b, vector<vector<bool>> &vis, vector<vector<char>> &board) {
        if(i < 0 || i >= rsz || j < 0 || j >= csz || board[i][j] == 'X' || vis[i][j]) return;
        vis[i][j] = true;
        if(!b) board[i][j] = 'X';
        dfs(rsz, csz, i-1, j, b, vis, board);
        dfs(rsz, csz, i+1, j, b, vis, board);
        dfs(rsz, csz, i, j-1, b, vis, board);
        dfs(rsz, csz, i, j+1, b, vis, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int rsz = board.size(), csz = board[0].size();
        vector<vector<bool>> vis(rsz, vector<bool>(csz, false));    // 2d vector initialize
        for(int col = 0; col < csz; ++col) {
            if(board[0][col] == 'O') 
                dfs(rsz, csz, 0, col, true, vis, board);
            if(board[rsz-1][col] == 'O')
                dfs(rsz, csz, rsz-1, col, true, vis, board);
        }
        for(int row = 0; row < rsz; ++row) {
            if(board[row][0] == 'O')
                dfs(rsz, csz, row, 0, true, vis, board);
            if(board[row][csz-1] == 'O')
                dfs(rsz, csz, row, csz-1, true, vis, board);
        }      
        for(int i = 1; i < rsz-1; ++i) {
            for(int j = 1; j < csz-1; ++j) {
                if(board[i][j] == 'O' && !vis[i][j]) 
                    dfs(rsz, csz, i, j, false, vis, board);
            }
        }
    }
};