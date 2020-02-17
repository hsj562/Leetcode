class Solution {
private:
    void solve(int pos, vector<int> nums, vector<vector<int>> &ret) {
        if(pos == nums.size()) {
            ret.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); ++i) {
            if(i != pos && nums[i] == nums[pos]) continue;
            swap(nums[pos], nums[i]);
            solve(pos+1, nums, ret);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        solve(0, nums, ret);
        return ret;
    }
};