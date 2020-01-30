class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        for(int i = 1; i < nums.size(); ++i) {
            dp.push_back(max(dp[i-1]+nums[i], nums[i]));
        } 
        return *max_element(dp.begin(), dp.end());
    }
};
/** O(1) space complexity **/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int ret = dp;
        for(int i = 1; i < nums.size(); ++i) {
            dp = max(dp+nums[i], nums[i]);
            ret = max(ret, dp);
        } 
        return ret;
    }
};