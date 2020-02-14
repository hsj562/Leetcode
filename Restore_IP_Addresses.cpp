class Solution {
private:
    bool isValid(string s) {
        if( (s.length() == 1 || s[0] != '0') && stoi(s) < 256) return true; // boolean function
        return false;
    }
    void solve(int idx, int seg, vector<string> &sub, string s, vector<string> &ret) {
        if(seg == 4 && idx == s.length()) {
            string pb;
            for(int i = 0; i < sub.size(); ++i) {
                pb += sub[i];
                if(i != sub.size()-1) {
                    pb += '.';
                }
            }
            ret.push_back(pb);
            return;
        } else if(seg == 4 || idx == s.length()) {return;}
        for(int len = 1; len <= 3; ++len) {
            if(idx + len > s.length()) {break;}
            string substr = s.substr(idx, len);
            if(isValid(substr)) {
                sub.push_back(substr);
                solve(idx+len, seg+1, sub, s, ret);
                sub.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return {};
        vector<string> ret;
        vector<string> sub; // do not set the size
        solve(0, 0, sub, s, ret);
        return ret;
    }
};