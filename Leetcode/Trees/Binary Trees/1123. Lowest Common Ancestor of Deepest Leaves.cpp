// Problem Link - https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    ll op = INT_MIN;
    void DFS(TreeNode* root, TreeNode* &a, TreeNode* &b, ll d)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
        {
            if(d>op)
                op = d, a = root, b = nullptr;
            else if(d==op and a)
                b = root;
            return;
        }
        DFS(root->left,a,b,d+1);
        DFS(root->right,a,b,d+1);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b)
    {
        if(root==nullptr)
            return nullptr;
        TreeNode* lef = lca(root->left,a,b);
        TreeNode* rig = lca(root->right,a,b);
        if(root==a)
            return a;
        else if(root==b)
            return b;
        else if(lef and rig)
            return root;
        else if(lef)
            return lef;
        else if(rig)
            return rig;
        return nullptr;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* a = nullptr;
        TreeNode* b = nullptr;
        DFS(root,a,b,0);
        if(!a)
            return b;
        if(!b)
            return a;
        return lca(root,a,b);
    }
};