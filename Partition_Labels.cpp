class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(27);
        for(int i = 0; i < S.size(); ++i) {
            last[S[i]-'a'] = i;
        }
        vector<int> ret;
        int s = 0, e = last[S[0]-'a'];
        /** Note that it may be an infinite loop **/
        while(s < S.size() && e < S.size()) {
            for(int i = s+1; i < e; ++i) {
                e = max(e, last[S[i]-'a']);
            }
            ret.push_back(e-s+1);
            s = e+1;    // here
            if(s < S.size()) {
                e = last[S[s]-'a'];
            }
        }
        return ret;
    }
};  