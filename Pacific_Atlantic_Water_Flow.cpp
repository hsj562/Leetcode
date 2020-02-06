class Solution {
private:
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isValid(int i, int j, int r, int c) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    void dfs(int i, int j, int r, int c, vector<vector<bool>> &ocean, vector<vector<int>> &matrix) {
        ocean[i][j] = true;
        for(auto d: dir) {
            int nr = i+d[0], nc = j+d[1];
            if(isValid(nr, nc, r, c) && !ocean[nr][nc] && matrix[nr][nc] >= matrix[i][j]) {
                dfs(nr, nc, r, c, ocean, matrix);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty()) {return {};}
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<bool>> pac(r, vector<bool>(c, false));
        vector<vector<bool>> atl(r, vector<bool>(c, false));
        for(int i = 0; i < r; ++i) {
            if(!pac[i][0])
                dfs(i, 0, r, c, pac, matrix);
            if(!atl[i][c-1])
                dfs(i, c-1, r, c, atl, matrix);
        }
        for(int i = 0; i < c; ++i) {
            if(!pac[0][i])
                dfs(0, i, r, c, pac, matrix);
            if(!atl[r-1][i])
                dfs(r-1, i, r, c, atl, matrix);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < r; ++i) 
            for(int j = 0; j < c; ++j) 
                if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
        return ans;
    }
};