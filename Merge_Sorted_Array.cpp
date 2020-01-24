class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /** Note that if we compare from behind then we don't need extra memory for copying nums1 **/
        int left = m-1, right = n-1, res = n+m-1;
        while(left >= 0 && right >= 0) {
            if(nums1[left] > nums2[right]) {
                nums1[res--] = nums1[left--];
            } else {
                nums1[res--] = nums2[right--];
            }
        }
        while(right >= 0) {
            nums1[res--] = nums2[right--];
        }
    }
};