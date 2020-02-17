class Solution {
private:
    void solve(int pos, vector<int> &nums, vector<vector<int>> &ret) {
        if(pos == nums.size()) {
            ret.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); ++i) {
            swap(nums[pos], nums[i]);
            solve(pos+1, nums, ret);
            swap(nums[pos], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<vector<int>> ret;
        solve(0, nums, ret);
        return ret;
    }
};