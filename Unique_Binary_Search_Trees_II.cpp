/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> ret;
        if(start > end) {return {NULL};}
        for(int i = start; i <= end; ++i) {
            vector<TreeNode*> leftsub = solve(start, i-1);
            vector<TreeNode*> rightsub = solve(i+1, end);
            for(int l = 0; l < leftsub.size(); ++l) {
                for(int r = 0; r < rightsub.size(); ++r) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftsub[l];
                    root->right = rightsub[r];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {return vector<TreeNode*>(0);}
        return solve(1,n);
    }
};