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
    void Traverse(TreeNode *root, string cur, vector<string> &ret) {
        cur += to_string(root->val);
        if(!root->left && !root->right) {
            ret.push_back(cur);
            return;
        } else cur += "->";
        if(root->left) 
            Traverse(root->left, cur, ret);
        if(root->right)
            Traverse(root->right, cur, ret);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) {return {};}    
        vector<string> ret;
        Traverse(root, "", ret);
        return ret;
    }
};