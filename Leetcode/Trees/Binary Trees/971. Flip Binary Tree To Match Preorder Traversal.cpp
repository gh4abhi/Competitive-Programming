// Problem Link - https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

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
    
    bool DFS(ll &ind, TreeNode* root, vector<ll> &vect, vector<ll> &ans)
    {
        if(root==nullptr)
        {
            ind--;
            return true;
        }
        if(ind>=vect.size())
            return false;
        ll op1 = ind, op2 = ind;
        ll ok = 0;
        if(root->val==vect[op1] and DFS(++op1,root->left,vect,ans) and DFS(++op1,root->right,vect,ans))
            ind=op1,ok = 1;
        if(!ok and root->val==vect[op2] and DFS(++op2,root->right,vect,ans) and DFS(++op2,root->left,vect,ans))
            ind=op2,ans.push_back(root->val),ok = 1;
        return ok;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<ll> ans;
        ll ind = 0;
        if(DFS(ind,root,voyage,ans))
            return ans;
        return {-1};
    }
};