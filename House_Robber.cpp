class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        int dp[n+1];    // it can be more space-saving (int dp[2];)
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; ++i)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        return dp[n];
    }
};