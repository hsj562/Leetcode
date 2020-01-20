class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        /** Be careful of the empty string **/
        if(len == 0) {
            return "";
        }
        char s_sharp[2*len+10];
        for(int i = 0; i < len; ++i) {
            s_sharp[2*i] = '#';
            s_sharp[2*i+1] = s[i];
        }
        s_sharp[2*len] = '#';
        s_sharp[2*len+1] = '\0';
        int right = 0, center = 0;
        int size = 2*len+1;
        int L[size];
        memset(L, 0, sizeof(L));
        for(int i = 0; i < size; ++i) {
            if(i < right) {
                L[i] = min(right-i, L[2*center-i]);
            }
            int left_tmp = i-L[i]-1;
            int right_tmp = i+L[i]+1;
            while(left_tmp >= 0 && right_tmp < size && s_sharp[left_tmp] == s_sharp[right_tmp]) {
                L[i]++;
                left_tmp--, right_tmp++;
            }
            if(i + L[i] > right) {
                center = i;
                right = i + L[i];
            }
        }
        int max_cnt = 0;
        int pos = 0;
        for(int i = 0; i < size; ++i) {
            if(L[i] > max_cnt) {
                max_cnt = L[i];
                pos = i;
            }  
        }
        string ret;
        for(int i = pos-max_cnt; i <= pos+max_cnt; ++i) {
            if(s_sharp[i] == '#') {
                continue;
            } else {
                ret.push_back(s_sharp[i]);
            }
        }
        return ret;
    }
};