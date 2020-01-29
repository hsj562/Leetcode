class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int rm = 0;
        int s = intervals.size();
        vector<int> last = {INT_MIN, INT_MIN};
        for(int i = 0; i < s; ++i) {
            if(intervals[i][0] < last[1]) 
                rm++;
            else
                last = intervals[i];
        }
        return rm;
    }
};