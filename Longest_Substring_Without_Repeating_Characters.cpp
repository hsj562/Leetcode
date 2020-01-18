/** O(N^2) way **/
/**
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        
        int max_cnt = -1;
        int cnt = 0;
        while(s[tail] != '\0') {
            bool valid = true;
            for(int i = tail-1; i >= head; --i) {
                if(s[i] == s[tail]) {
                    if(cnt > max_cnt) {
                        max_cnt = cnt;
                    }
                    cnt -= (i-head);
                    head = i+1;
                    valid = false;
                    break;
                }
            }
            if(valid) {
                ++cnt;
            }
            ++tail;
        }
        if(cnt > max_cnt) {max_cnt = cnt;}
        return max_cnt;
    }
};
**/
/** O(N) way **/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size();
        std::unordered_map<char,int> maphash;
        int front = 0, tail = 0;
        /** Note that it may be an empty string **/
        int max_cnt = 0;
        for(; tail < l; ++tail) {
            auto it = maphash.find(s[tail]);
            if(it != maphash.end()) {   
                /** Don't need to clear the whole hash, we can just determine whether the position of found element and front **/
                front = std::max( front, (it->second) + 1);
            }
            /** Note "+1" **/
            max_cnt = std::max(max_cnt, tail - front + 1);
            maphash[s[tail]] = tail;
        }
        return max_cnt;
    }
};