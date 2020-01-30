class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() <= 0) {return true;} 
        int p = 0;
        for(char c:t) {
            if(c == s[p]) {
                p++;
                if(p == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};