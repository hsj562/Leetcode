class Solution {
private:
    void solve(int start, vector<int> &nums, vector<int> &ans, vector<vector<int>> &ret) {
        ret.push_back(ans);
        for(int i = start; i < nums.size(); ++i) {
            if(i != start && nums[i] == nums[i-1]) continue;
            ans.push_back(nums[i]);
            solve(i+1, nums, ans, ret);
            ans.pop_back();
        }        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, ans, ret);
        return ret;
    }
};