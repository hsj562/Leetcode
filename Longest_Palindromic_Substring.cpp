class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        /** Be careful of the empty string **/
        if(len == 0) {
            return "";
        }
        bool dp[len][len];
        memset(dp, false, sizeof(dp));
        int S = 0, E = 0;
        int max_cnt = 1;
        char ret[len+1];
        for(int i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        for(int i = 0; i < len-1; ++i) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(max_cnt < 2) {
                    max_cnt = 2;
                    S = i, E = i+1;
                }
            }
        }
        /** Be careful of the bound of loops **/
        for(int l = 3; l <= len; ++l) {
            for(int start = 0; start <= len-l; ++start) {
                if(dp[start+1][start+l-2] && s[start] == s[start+l-1]) {
                    dp[start][start+l-1] = true;
                    if(l > max_cnt) {
                        max_cnt = l;
                        S = start, E = start+l-1;
                    }
                }
            }
        }
        for(int i = S; i <= E; ++i) {
            ret[i-S] = s[i];
        }
        /** Note that the last character of the returned string **/
        ret[E+1-S] = '\0';
        return ret;
    }
};