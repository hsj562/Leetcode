/** original method **/
bool compare(const vector<int> &v1, const vector<int> &v2)
{
    if(v1[0] == v2[0]) {
        return v1[1] > v2[1];
    }  
    return v1[0] < v2[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int s = people.size();
        vector<vector<int>> ret(s);
        sort(people.begin(), people.end(), compare);
        for(auto p: people) {
            int pos = p[1];
            int cnt = 0;
            for(auto &space: ret) {
                if(space.empty() && cnt == pos) {
                    space.push_back(p[0]);
                    space.push_back(p[1]);
                    break;
                } else if(space.empty()) {
                    cnt++;
                }
            }
        }
        return ret;
    }
};
/** insertion method **/
bool rev_compare(const vector<int> &v1, const vector<int> &v2)
{
    if(v1[0] == v2[0]) {return v1[1] < v2[1];}
    return v1[0] > v2[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), rev_compare);
        vector<vector<int>> ret;
        for(auto p:people) {
            ret.insert(ret.begin()+p[1], p);
        }
        return ret;
    }
};