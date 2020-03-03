class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i = 0; i < len; ++i) {
            for(string word: wordDict) {
                const int wlen = word.length();
                if(dp[i] && s.substr(i, wlen) == word) {
                    dp[i+wlen] = true;
                }
            }
        }
        return dp[len];
    }
};