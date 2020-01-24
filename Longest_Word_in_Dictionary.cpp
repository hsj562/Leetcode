class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(),[](const string &a, const string &b){if(a.size() == b.size()){return strcmp(a.c_str() , b.c_str()) > 0 ;} else {return a.size() > b.size();} } );
        for(string str: d) {
            int ptr1 = 0, ptr2 = 0;
            while(ptr1 < s.size() && ptr2 < str.size()) {
                if(s[ptr1] == str[ptr2]) {
                    ptr2++;
                }
                ptr1++;
            }
            if(ptr2 == str.size()) {
                return str;
            }
        }
        return "";
    }
};