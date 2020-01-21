class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        if(right < 0) {
            return 0;
        }  
        int max_area = min(height[left], height[right]) * (right - left);
        while(left < right) {
            int prev_left = left;
            int prev_right = right;
            if(height[left] < height[right]) {
                do {
                    left++;
                } while(height[left] < height[prev_left]);
                max_area = max(max_area, min(height[left], height[right])*(right-left) );
            } else {
                do {
                    right--;
                } while(height[right] < height[prev_right]);
                max_area = max(max_area, min(height[left], height[right]) * (right - left));
            }
        }
        return max_area;
    }
};