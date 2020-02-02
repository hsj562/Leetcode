/** lower_bound and upper_bound implementation **/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        if(it1 == nums.end() || *it1 != target) {
            return {-1,-1};
        } else if(it2 == nums.end()) {
            return {(int)(it1-nums.begin()), nums.size()-1};
        } else {
            return {(int)(it1-nums.begin()), (int)(it2-nums.begin())-1};
        }
    }
};
/** General solution **/
class Solution {
public:
    vector<int>searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {return {-1,-1};}
        int lo = 0, hi = nums.size()-1;
        int start = -1, end = -1;
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < target) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        /** we only need to modify hi **/
        hi = nums.size()-1;
        if(nums[lo] == target) start = lo;
        else return {-1, -1};
        while(lo < hi) {
            int mid = lo + (hi-lo+1)/2; // prevent from infinite loop
            if(nums[mid] > target) {
                hi = mid-1;
            } else {
                lo = mid;
            }
        }
        end = lo;
        return {start,end};
    }
};