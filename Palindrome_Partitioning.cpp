class Solution {
private:
    bool isPal(string s, int start, int end) {
        while(start < end) 
            if(s[start++] != s[end--]) return false;
        return true;
    }
    void solve(int start, string s, vector<string> &ans, vector<vector<string>> &ret) {
        if(start == s.length()) {
            ret.push_back(ans);
            return;
        }
        for(int i = start; i < s.length(); ++i) {
            if(isPal(s, start, i)) {
                ans.push_back(s.substr(start, i-start+1));
                solve(i+1, s, ans, ret);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> ans;
        solve(0, s, ans, ret);
        return ret;
    }
};