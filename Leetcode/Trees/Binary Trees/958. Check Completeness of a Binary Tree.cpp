// Problem Link - https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    ll flag = 1;
    bool DFS(TreeNode* root, ll level, unordered_map<ll,ll> &m)
    {
        if(root==nullptr)
        {
            if(m.count(level+1) and m[level+1]!=-1)
                return false;
            else if(m[level]>0 and flag)
                flag = 0;
            else if(m[level]>0 and !flag)
                return false;
            m[level] = -1;
            return true;
        }
        if(m[level]==-1)
            return false;
        m[level]++;
        return DFS(root->left,level+1,m) and DFS(root->right,level+1,m);
    }
    
    bool isCompleteTree(TreeNode* root) {
        unordered_map<ll,ll> m;
        return DFS(root,0,m);
    }
};