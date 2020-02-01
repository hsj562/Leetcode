/** binary search **/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters.back() <= target) {return letters.front();}
        int l = 0, r = letters.size()-1;
        while(l < r) {
            int mid = (l+r)/2;
            if(letters[mid] > target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return letters[l];        
    }
};
/** upper_bound **/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        if(it == letters.end())
            return letters.front();
        return *it;
    }
};