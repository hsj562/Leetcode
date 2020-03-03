/** DP O(N^2) **/
bool compare(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) return v1[0] < v2[0];
    else return v1[1] < v2[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), compare);
        const int n = pairs.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(pairs[j][1] < pairs[i][0]) 
                    dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        int ret = 1;
        for(int i = 0; i < n; ++i) ret = max(ret, dp[i]);
        return ret;
    }
};
/** Greedy O(NlogN) **/
bool compare(vector<int> &v1, vector<int> &v2) {
    if(v1[1] == v2[1]) return v1[0] < v2[0];
    else return v1[1] < v2[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), compare);
        const int n = pairs.size();
        int ret = 1;
        int last = pairs[0][1];
        for(int i = 1; i < n; ++i) {
            if(pairs[i][0] > last) {
                ret++;
                last = pairs[i][1];
            }
        }
        return ret;
    }
};