class Solution {
private:
    void solve(int n, int total, int start, vector<int> &nums, vector<int> &ans, vector<vector<int>> &ret) {
        if(n == total) {
            ret.push_back(ans);
            return;
        }
        if(nums.size() - start < total - n)
            return;
        for(int i = start; i < nums.size(); ++i) {
            ans.push_back(nums[i]);
            solve(n+1, total, i+1, nums, ans, ret);
            solve(n+1, total+1, i+1, nums, ans, ret);   // total is not always the same
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> ans;
        ret.push_back(ans);
        solve(0, 1, 0, nums, ans, ret);
        return ret;
    }
};