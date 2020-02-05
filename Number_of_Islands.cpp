class Solution {
private:
    void dfs(const int row, const int col, const int i, const int j, vector<vector<char>>& grid) {
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(row, col, i-1, j, grid);
        dfs(row, col, i+1, j, grid);
        dfs(row, col, i, j-1, grid);
        dfs(row, col, i, j+1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    dfs(row, col, i, j, grid);
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};