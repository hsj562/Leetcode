class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) {return 0;}
        queue<pair<int,int>> q;
        q.push({0,n});
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 1; i * i <= p.second; ++i) {
                int re = p.second - i * i;
                if(re == 0) {
                    return 1+p.first;
                }
                q.push({1+p.first, re});
            }
        }
        return -1;  // this should not happen
    }
};