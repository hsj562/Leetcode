class Solution {
private:
    void dfs(int pos, string str, string digits, vector<string> dig2a, vector<string> &ret) {
        if(pos == digits.length()) { 
            ret.push_back(str);
            return;
        }
        int num = digits[pos] - '0' - 2;
        for(int i = 0; i < dig2a[num].size(); ++i) 
            dfs(pos+1, str+dig2a[num][i], digits, dig2a, ret);
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> dig2a(8);
        char c = 'a';
        for(int i = 0; i < 8; ++i, c+=3) {
            dig2a[i] += c;
            dig2a[i] += c+1;
            dig2a[i] += c+2;
            if(i == 5 || i == 7) {
                dig2a[i] += c+3;
                c++;
            }
        }
        vector<string> ret;
        dfs(0, "", digits, dig2a, ret);
        return ret;
    }
};