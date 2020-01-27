typedef pair<char,int> pc;
/** Solution 1 (hash map + maxheap) O(NlogN)**/
class Compare {
    public:
        bool operator()(const pc p1, const pc p2)
        {
            return p1.second < p2.second;
        }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int len = s.size();
        for(int i = 0; i < len; ++i) {
            freq[s[i]]++;
        }                
        priority_queue<pc, vector<pc>, Compare> pq;
        for(pc p: freq) {
            pq.push(p);
        }
        string ret;
        while(!pq.empty()) {
            pc ct = pq.top();
            ret += string(ct.second, ct.first);
            pq.pop();
        }
        return ret;
    }
};
/** Solution 2 (bucket sort) O(N)**/
class Solution {
    public:
    string frequencySort(string s) {
        unordered_map<pc> umap;
        int len = s.size();
        for(char c: s) {
            umap[c]++;
        }
        vector<vector<char>> bucket(len+1);
        for(auto p:umap) {
            bucket[p.second].push_back(p.first);
        }
        string ret;
        for(int i = len; i >= 0; --i) {
            if(!bucket[i].empty()) {
                for(auto it = bucket[i].begin(); it != bucket[i].end(); ++it)
                    ret += string(*it,i);
            }
        }
        return ret;
    }
};