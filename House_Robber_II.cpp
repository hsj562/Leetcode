class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        if(n == 1) return nums[0];
        int dp[n+1];
        int ret = -1;
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < n; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        ret = dp[n-1];
        dp[1] = nums[1];
        for(int i = 2; i < n; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);    // Note the difference
        ret = max(ret, dp[n-1]);
        return ret;
    }
};