// Problem Link - https://leetcode.com/problems/house-robber-iii/

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
    
    pair<ll,ll> robHelper(TreeNode* root)
    {
        if(root->left== nullptr and root->right==nullptr)
        {
            return make_pair(root->val,0);
        }
        
        ll lWith = 0, lWithout = 0, rWith = 0, rWithout = 0, finalWith = 0, finalWithout = 0;
        pair<ll,ll> l,r;
        if(root->left)
        {
             l = robHelper(root->left);
             lWith = l.first;
             lWithout = l.second;
        }
        if(root->right)
        {
             r = robHelper(root->right);
             
                 rWith = r.first;
                 rWithout = r.second;
             
        }
        finalWith = root->val + lWithout + rWithout;
        finalWithout = max(lWith,lWithout) + max(rWith,rWithout);
        return make_pair(finalWith, finalWithout);
    }
    
    int rob(TreeNode* root) {
        pair<ll,ll> ans = robHelper(root);
        return max(ans.first, ans.second);
    }
};
