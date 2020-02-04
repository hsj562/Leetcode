
class Solution {
public:
    struct point {
        int dis;
        int r, c;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dir[8][2] = {{1,1},{1,0},{0,1},{-1,1},{1,-1},{0,-1},{-1,0},{-1,-1}};    // 2-D array is much faster than vector
        int N = grid.size();
        if(grid[0][0] || grid[N-1][N-1]) {return -1;}
        queue<point> q;
        q.push({1,0,0});
        while(!q.empty()) {
            point cur = q.front();  
            q.pop();
            int cr = cur.r, cc = cur.c;
            if(cr == N-1 && cc == N-1) {return cur.dis;}
            for(auto d: dir) {
                int nr = cr+d[0], nc = cc+d[1];
                if(nr >= 0 && nc >= 0 && nr < N && nc < N && !grid[nr][nc]) {
                    if(nr == N-1 && nc == N-1) {return 1+cur.dis;}
                    q.push({1+cur.dis,nr,nc});
                    grid[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};