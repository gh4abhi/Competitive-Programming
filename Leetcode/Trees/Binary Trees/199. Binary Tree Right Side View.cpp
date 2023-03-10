// Problem Link - https://leetcode.com/problems/binary-tree-right-side-view/

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
    ll row = 0;
    void DFS(TreeNode* root, ll r, vector<ll>& ans)
    {
        if(root==nullptr)
            return;
        if(r>row)
            row = r, ans.push_back(root->val);
        DFS(root->right,r+1,ans);
        DFS(root->left,r+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root)
            ans.push_back(root->val);
        DFS(root,0,ans);
        return ans;
    }
};