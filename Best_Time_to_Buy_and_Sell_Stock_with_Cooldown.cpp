class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        const int n = prices.size();
        vector<int> buy(n+1, 0), sell(n+1, 0);
        buy[1] = -prices[0];    // note the init
        for(int i = 2; i <= n; ++i) {   
            buy[i] = max(sell[i-2]-prices[i-1], buy[i-1]);  // key
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);
        }       
        return sell[n];
    }
};