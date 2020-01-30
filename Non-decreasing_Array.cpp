class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int m = 0;
        for(int i = 1; i < nums.size() && m < 2; ++i) {
            if(nums[i] < nums[i-1]) {
                m++;
                /** Note that there are two cases if m = 1 **/
                if(i+1 < nums.size()) {
                    if(nums[i+1] >= nums[i-1]) { nums[i] = nums[i-1]; } // e.g. [1,3,2,4]
                    else if(i > 1 && nums[i-2] > nums[i]) { m++; } // e.g. [2,3,1,2]
                }
            }
        }
        return m < 2;
    }
};