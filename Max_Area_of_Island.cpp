class Solution {
private:
    int dfs(const int row, const int col, const int i, const int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= row || j < 0 || j >= col || !grid[i][j]) return 0;
        int ret = 1;
        grid[i][j] = 0;
        ret += dfs(row, col, i-1, j, grid);
        ret += dfs(row, col, i+1, j, grid);
        ret += dfs(row, col, i, j-1, grid);
        ret += dfs(row, col, i, j+1, grid);
        return ret;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int curMax = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j]) {
                    curMax = max(curMax, dfs(row, col, i, j, grid));
                }
            }
        }
        return curMax;
    }
};