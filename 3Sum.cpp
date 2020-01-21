class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int s = nums.size();
        if(s < 3) { return {}; }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int i = 0; i < s-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {continue;}
            int front = i+1, tail = s-1;
            int sum;
            while(front < tail) {
                sum = nums[i] + nums[front] + nums[tail];
                if(sum > 0) {
                    tail--;
                } else if(sum < 0){
                    front++;
                } else {
                    ret.push_back({nums[i], nums[front], nums[tail]});
                    front++, tail--;
                    while(front < tail && nums[front] == nums[front-1]) {front++;}
                    while(front < tail && nums[tail] == nums[tail+1]) {tail--;}
                }
            }
        }    
        return ret;    
    }
};