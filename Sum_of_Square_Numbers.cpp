class Solution {
public:
    bool judgeSquareSum(int c) {
        /** Note that the overflow problem **/
        long left = 0, right = (long)sqrt(c);        
        while(left <= right) {
            long ss = left*left + right*right;
            if(ss > c) {
                right--;
            } else if(ss < c) {
                left++;
            } else {
                return true;
            }
        }
        return false;
    }
};