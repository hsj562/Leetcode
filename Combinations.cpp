class Solution {
private:
    void solve(int start, int ct, int n, int k, vector<int> tmp, vector<vector<int>> &ret) {
        if(ct == k) {
            ret.push_back(tmp);
            return;
        } 
        if(n-start+1 < k-ct) return;    // Note the condition
        for(int i = start; i <= n; ++i) {
            tmp.push_back(i);
            solve(i+1, ct+1, n, k, tmp, ret);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        solve(1, 0, n, k, {}, ret);
        return ret;
    }
};