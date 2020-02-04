class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(), wordList.end());
        if(uset.find(endWord) == uset.end()) {return 0;}        
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        uset.erase(beginWord);
        while(!q.empty()) {
            pair<int,string> p = q.front();
            q.pop();
            if(p.second == endWord) {return p.first;}
            for(int i = 0; i < p.second.length(); ++i) {
                string tmp = p.second;
                for(char c = 'a'; c <= 'z'; ++c) {  // if trace all wordList will TLE
                    tmp[i] = c;
                    if(uset.find(tmp) != uset.end() ) {
                        uset.erase(tmp);    // here to erase is faster!!
                        q.push({1+p.first, tmp});
                    }
                }
            }
        }
        return 0;
    }
};