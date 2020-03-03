class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int goal = 0;
        const int sz = nums.size();
        for(int num: nums) goal += num;
        if(goal % 2 != 0 ) return false;
        goal >>= 1;
        vector<int> dp(goal+1, 0);
        dp[0] = 1;
        for(int i = 0; i < sz; ++i) {
            for(int j = goal; j > 0; --j) {
                if(nums[i] > j) continue;
                else dp[j] = max(dp[j-nums[i]] , dp[j]);
            }
        }
        return dp[goal] == 1;
    }
};