// Problem Link - https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

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
    
    TreeNode* DFS(TreeNode* root, ll limit, ll sum)
    {
        if(root==nullptr)
            return nullptr;
        if(!root->left and !root->right)
        {
            if(sum+root->val<limit)
                return nullptr;
            return root;
        }
        root->left = DFS(root->left,limit,sum+root->val);
        root->right = DFS(root->right,limit,sum+root->val);
        if(root->left or root->right)
            return root;
        return nullptr;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return DFS(root,limit,0);
    }
};