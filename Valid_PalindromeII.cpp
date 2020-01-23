class Solution {
public:
    bool validSubPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] == s[r]) {
                l++, r--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left] == s[right]) {
                left++, right--;
            } else {
                if(validSubPalindrome(s, left+1, right) ) {
                    return true;
                } else if(validSubPalindrome(s, left, right-1) ){
                    return true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};