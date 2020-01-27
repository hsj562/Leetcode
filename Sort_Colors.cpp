class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        int s = nums.size();
        for(int i = 0; i < s; ++i) {
                if(nums[i] == 0) {            
                    swap(nums[p0], nums[i]);
                    if(nums[i] == 1) {
                        swap(nums[p1], nums[i]);
                    }
                    p0++, p1++;
                } else if(nums[i] == 1) {
                    swap(nums[p1++], nums[i]);
                }
        }
    }
};