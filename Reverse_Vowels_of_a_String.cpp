class Solution {
public:
    bool isVowel(char c) {
        switch (c)
        {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U':
            return true;
        default:
            return false;
        }
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(!isVowel(s[left])) left++;
            else if(!isVowel(s[right])) right--;
            else {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};