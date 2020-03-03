class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            dp[i] = -1;
            for(int money: coins) {
                if(i < money) continue;
                else if(i == money) dp[i] = 1;
                else if(dp[i] == -1 && dp[i-money] != -1) 
                    dp[i] = 1 + dp[i-money];
                else if(dp[i] != -1 && dp[i-money] != -1)
                    dp[i] = std::min(dp[i], 1+dp[i-money]);
            }
        }
        return dp[amount];
    }
};