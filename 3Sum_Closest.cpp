class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int s = nums.size();
        if(s < 3) {return 0;}
        sort(nums.begin(), nums.end());
        int dif = 1 << 30, ret = 0;
        for(int i = 0; i < s; ++i) {
            int head = i+1, tail = s-1;
            while(head < tail) {
                int sum = nums[i] + nums[head] + nums[tail];
                if(abs(sum-target) < dif) {
                    dif = abs(sum-target);
                    ret = sum;
                }
                if(sum > target) {
                    tail--;
                } else if(sum < target) {
                    head++;
                } else {
                    return target;
                }
            }
        }
        return ret;
    }
};