/** DP TC:O(N^2) SC:O(N)**/
class Solution {
public:
    inline int sgn(int num) {
        if(num > 0) return 1;
        else if(num == 0) return 0; //here
        return -1;
    }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        int dp[n], sign[n];
        for(int i = 0; i < n; ++i) {
            sign[i] = 0;
            dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                int curSign = sgn(nums[i] - nums[j]);
                if(curSign == 0) continue;  // here
                else if(curSign != sign[j] && dp[i] < 1+dp[j]) {
                    dp[i] = 1+dp[j];
                    sign[i] = curSign;
                }   
            }
        }
        int curMax = 0;
        for(int i = 0; i < n; ++i) curMax = max(curMax, abs(dp[i]));
        return curMax;
    }
};
/** Linear DP TC:O(N) SC:O(1) **/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int up = 1, down = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i-1]) {
                up = down + 1;
            } else if(nums[i] < nums[i-1]) {
                down = up + 1;
            }
        } 
        return max(down, up);
    }
};