// Problem Link - https://leetcode.com/problems/find-duplicate-subtrees/

#define ll int

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    string DFS(TreeNode* root, vector<TreeNode*> &ans, map<string,ll> &m)
    {
        if(root==nullptr)
            return "";
        string lef = DFS(root->left,ans,m);
        string rig = DFS(root->right,ans,m);
        string op = to_string(root->val) + '$' + lef + '$' + rig;
        if(m[op]==1)
            ans.push_back(root);
        m[op]++;
        return op;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string,ll> m;
        DFS(root,ans,m);
        return ans;
    }
};