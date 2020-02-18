class Solution {
private:
    void solve(int sum, int start, vector<int> &comb, vector<int> &candidates, int target, vector<vector<int>> &ret) {
        if(sum > target || start > candidates.size()) return;
        else if(sum == target) {
            ret.push_back(comb);
            return;
        }
        for(int i = start; i < candidates.size(); ++i) {
            if(i != start && candidates[i] == candidates[i-1]) continue;    // skip dup
            comb.push_back(candidates[i]);
            solve(sum+candidates[i], i+1, comb, candidates, target, ret);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> comb;
        solve(0, 0, comb, candidates, target, ret);        
        return ret;
    }
};