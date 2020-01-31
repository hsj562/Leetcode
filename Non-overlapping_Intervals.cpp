class Solution {
private:
    static bool compare(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 0) {return 0;}
        sort(intervals.begin(), intervals.end(), compare);
        int rm = 0;
        vector<int> last = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < last[1]) 
                rm++;
            else
                last = intervals[i];
        }
        return rm;
    }
};