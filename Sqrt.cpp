class Solution {
private:
    int bsearch(int l, int r, int x) {
        /** Note that it may overflow **/
        long long mid = (l+r)/2;
        /** we can also use if(x/mid == mid) to prevent overflow **/
        if(mid * mid < x && (mid+1) * (mid+1) <= x ) {
            return bsearch(mid+1, r, x);
        } else if(mid * mid > x) {
            return bsearch(l, mid, x);
        }
        return mid;
    }
public:
    int mySqrt(int x) {
        /** start at 0 and end at x **/
        int left = 0, right = x;
        return bsearch(left, right, x);   
    }
};