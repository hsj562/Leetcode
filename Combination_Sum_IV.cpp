class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<unsigned int> dp(target+1, 0);   // note that signed may overflow
        dp[0] = 1;
        for(int t = 1; t <= target; ++t) {  // the different order counted as different combination
            for(int num : nums) {
                if(num > t) break;
                dp[t] += dp[t-num];
            }
        }
        return dp[target];
    }
};