/** Method 1 **/
class Solution {
public:
    int integerBreak(int n) {
        int curMax = n-1;
        for(int i = 2; i < n; ++i) {
            int q = n/i, r = n%i;
            int m = 1;
            for(int j = 0; j < i-r; ++j)
                m *= q;
            for(int j = 0; j < r; ++j)
                m *= (q+1);
            curMax = max(curMax, m);
        }      
        return curMax;
    }
};
/** Method 2 **/
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; ++i) {
            dp[i] = 0;
            for(int j = 1; j < i; ++j)
                dp[i] = max(dp[i], max(i-j, dp[i-j]) * max(j, dp[j]) );
        }
        return dp[n];
    }
};
