class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n <= 0) return 0;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = s[0] == '0'? 0:1;
        for(int i = 2; i <= n; ++i) {
            int one = stoi(s.substr(i-1, 1));
            int two = stoi(s.substr(i-2, 2));
            dp[i] = 0;
            if(1 <= one && one <= 9) dp[i] += dp[i-1];
            if(10 <= two && two <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};