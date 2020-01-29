    bool compare(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            if(points.empty()) {return 0;}
            sort(points.begin(), points.end(), compare);
            int cnt = 1;
            int last = points[0][1];
            for(int i = 1; i < points.size(); ++i) {
                if(last < points[i][0]) {
                    cnt++;
                    last = points[i][1];
                }
            }        
            return cnt;
        }
    };