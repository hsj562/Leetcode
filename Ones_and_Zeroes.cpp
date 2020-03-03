class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string str: strs) {
            int one = 0, zero = 0;
            for(char c: str) {
                if(c == '0') zero++;
                else one++;
            }
            for(int i = m; i >= zero; --i) {    // Note that the bound
                for(int j = n; j >= one; --j) {
                    dp[i][j] = max(dp[i-zero][j-one] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};