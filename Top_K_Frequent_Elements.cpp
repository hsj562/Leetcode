class Compare {
    public:
        bool operator()(pair<int,int> p1, pair<int,int> p2) 
        {
            return p1.second > p2.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int n:nums) {
            umap[n]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(pair<int,int> it:umap) {
            pq.push(it);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ret;
        while(!pq.empty()) {
            int t = (pq.top()).first;
            ret.push_back(t);
            pq.pop();
        }
        return ret;
    }
};