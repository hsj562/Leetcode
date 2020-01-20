class Solution {
public:
    string convert(string s, int numRows) {
        string strarr[numRows];
        int len = s.size();
        int set = numRows + numRows - 2;
        if(set == 0) set = 1;
        for(int i = 0; i < len; ++i) {
            /** Note that division by zero **/
            int re = i % set;
            if( re < numRows) {
                strarr[re] += s[i];
            } else {
                strarr[set-re] += s[i];
            }
        }
        string ret;
        for(int i = 0; i < numRows; ++i) {
            ret += strarr[i];
        }
        return ret;
    }
};