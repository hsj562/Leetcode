/** DP O(N^2) **/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        int dp[n];
        for(int i = 0; i < n; ++i) dp[i] = 1;
        for(int i = 0; i < n; ++i) {
            int curMax = 1;
            for(int j = 0; j < i; ++j)
                if(nums[j] < nums[i]) curMax = max(curMax, 1+dp[j]);
            dp[i] = curMax;
        }
        int ret = 0;
        for(int i = 0; i < n; ++i) ret = max(ret, dp[i]);
        return ret;
    }
};
/** DP + BS O(NlogN) **/
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {    // len is correct but elements may wrong
        if(nums.empty()) return 0;
        const int n = nums.size();
        vector<int> dp;
        for(int num: nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if(it == dp.end()) dp.push_back(num);
            else *it = num;
        }
        return dp.size();
    }
};
