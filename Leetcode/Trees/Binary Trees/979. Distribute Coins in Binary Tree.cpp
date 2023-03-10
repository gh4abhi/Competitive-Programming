// Problem Link - https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    
    ll ans = 0;
    
    ll DFS(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        ll lef = DFS(root->left);
        ll rig = DFS(root->right);
        ans += (abs(lef)+abs(rig));
        return root->val + lef + rig -1;
    }
    
    int distributeCoins(TreeNode* root) {
        DFS(root);
        return ans;
    }
};