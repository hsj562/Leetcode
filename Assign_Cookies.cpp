class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gp = 0, sp = 0;
        int sg = g.size(), ss = s.size();
        int cnt = 0;
        while( gp < sg && sp < ss ) {
            if(g[gp] <= s[sp]) {
                sp++, cnt++;
            }
            gp++;
        }
        return cnt;
    }
};