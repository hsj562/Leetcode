class Solution {
private:
    void dfs(int s, bool vis[], vector<vector<int>>& M) {
        vis[s] = true;
        for(int i = 0; i < M.size(); ++i) {
            if(!vis[i] && M[s][i]) {
                dfs(i, vis, M);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) {return 0;}  
        int sz = M.size();      
        bool vis[sz];
        for(bool &v: vis) v = false;
        int ans = 0;
        for(int i = 0; i < sz; ++i) {
            if(!vis[i]) {
                dfs(i, vis, M);
                ans++;
            }
        }
        return ans;
    }
};