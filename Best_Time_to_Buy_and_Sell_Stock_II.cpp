/** Peak Valley Approach **/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        if(s <= 1) {return 0;}
        int ans = 0;
        int curMin = prices[0];
        for(int i = 1; i < s-1; ++i) {
            if(prices[i] >= prices[i-1] && prices[i] >= prices[i+1]) {  // local maximum
                ans += prices[i] - curMin;
                curMin = prices[i];
            } else if(prices[i] <= prices[i-1] && prices[i] <= prices[i+1]) { // local minimum
                curMin = prices[i];
            }
        }      
        if(prices[s-1] >= prices[s-2]) {
            ans += prices[s-1] - curMin;
        }
        return ans;
    }
};
/** Simple One Pass **/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i-1]) {
                ans += (prices[i] - prices[i-1]);
            }
        }
        return ans;
    }
};