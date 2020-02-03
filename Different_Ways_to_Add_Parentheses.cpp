namespace myoper {
    int add(int a, int b) {return a+b;}
    int minus(int a, int b) {return a-b;}
    int multi(int a, int b) {return a*b;}
}
class Solution {
private:
    unordered_map<string,vector<int>> umap;
    vector<int> solve(string input) {
        if(umap.find(input) != umap.end()) {return umap[input];}
        vector<int> ans;
        for(int i = 0; i < input.length(); ++i) {
            char op = input[i];
            if(op == '+' || op == '-' || op == '*') {
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);

                const vector<int> v1 = solve(left);
                const vector<int> v2 = solve(right);

                function<int(int,int)> func;
                switch(op) {
                    case '+': 
                        func = myoper::add;
                        break;
                    case '-':
                        func = myoper::minus;
                        break;
                    case '*':
                        func = myoper::multi;
                }
                for(int sub1: v1) {
                    for(int sub2 : v2) 
                        ans.push_back(func(sub1, sub2));
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(input));
        umap[input] = ans;
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        return solve(input);
    }
};