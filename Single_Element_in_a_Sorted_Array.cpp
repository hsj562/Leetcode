class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while(lo < hi) {
            int mid = (lo + hi)/2;
            if(mid&1) { // odd
                if(nums[mid] == nums[mid-1]) {
                    lo = mid+1;
                } else if(nums[mid] == nums[mid+1] ){
                    hi = mid-1;
                } else {
                    return nums[mid];
                }
            } else {    // even
                if(nums[mid] == nums[mid-1]) {
                    hi = mid-2;
                } else if(nums[mid] == nums[mid+1]) {
                    lo = mid+2;
                } else {
                    return nums[mid];
                }
            }
        }
        return nums[lo];
    }
};