class Solution {
private:
    int partition(vector<int>& nums, int left, int right, int k) {
        int mid = (left+right)/2;
        swap(nums[mid], nums[right]);
        int piv = nums[right];
        int i = left;
        for(int j = left; j < right; ++j) {
            if(nums[j] < piv) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        if(i < k) {
            return partition(nums, i+1, right, k);
        } else if(i > k) {
            return partition(nums, left, i-1, k);
        } else {
            return nums[i];
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return partition(nums, 0, n-1, n-k);
    }
};