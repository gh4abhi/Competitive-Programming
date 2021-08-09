// Problem Link - https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    ll maxi = *max_element(nums.begin(),nums.end());
    ll pos = find(nums.begin(),nums.end(),maxi) - nums.begin();
    TreeNode* root = new TreeNode(maxi);    
    vector<int> vl,vr;    
    vl.assign(nums.begin(),nums.begin()+pos);
        if(vl.size()>0)
        {
            root->left = constructMaximumBinaryTree(vl);
        }
    vr.assign(nums.begin()+pos+1,nums.end());
        if(vr.size()>0)
        {
            root->right = constructMaximumBinaryTree(vr);
        }
        return root;
    }
};
