class Solution {
private:
    void solve(int sum, int num, int start, int k, int n, vector<int> &comb, vector<vector<int>> &ret) {
        if(num > k || sum > n) return; 
        if(sum == n && num == k) {
            ret.push_back(comb);
            return;
        }
        for(int i = start; i < 10; ++i) {
            comb.push_back(i);
            solve(sum+i, num+1, i+1, k, n, comb, ret);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> comb;
        solve(0, 0, 1, k, n, comb, ret);
        return ret;
    }
};