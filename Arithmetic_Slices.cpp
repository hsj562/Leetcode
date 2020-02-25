class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        int dp[n];
        dp[0] = dp[1] = 0;
        for(int i = 2; i < n; ++i) {
            if(A[i]-A[i-1] == A[i-1]-A[i-2]) {
                dp[i] = 2 * dp[i-1] - dp[i-2] + 1;  // dp[i-1] + (dp[i-1] - dp[i-2]) + 1 
            } else 
                dp[i] = dp[i-1];
        }
        return dp[n-1];
    }
};