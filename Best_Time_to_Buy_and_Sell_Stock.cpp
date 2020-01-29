class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if(prices.size() <= 1) {return 0;}
        int curMin = prices[0], curMax = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > curMax) {
                curMax = prices[i];
            } else if(prices[i] < curMin) {
                ans = max(ans, curMax-curMin);
                curMin = curMax = prices[i];
            }
        }
        ans = max(ans, curMax-curMin);
        return ans;
    }
};