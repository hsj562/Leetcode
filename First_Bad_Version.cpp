// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /** Note that it's 1-base **/
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2; // it can avoid overflow
            if(isBadVersion(mid)) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }    
        return lo;  
    }
};