class Solution {
public:
    int myAtoi(string str) {
        long long num = 0;
        int ret = sscanf(str.c_str(), "%lld", &num);
        if(ret == 0) {
            return 0;
        } else {
            if(num > INT32_MAX) {
                num = INT32_MAX;
            }
            if(num < INT32_MIN) {
                num = INT32_MIN;
            }
        }
        return num;
    }
};