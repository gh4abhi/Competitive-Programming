// Problem Link - https://leetcode.com/problems/construct-string-from-binary-tree/

#define ll long long

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
    
    string ans = "";
    
    void DFS(TreeNode* root)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
        {
            ans += to_string(root->val);
            return;
        }
        ans += to_string(root->val);
        ans += '(';
        DFS(root->left);
        ans += ')';
        if(root->right)
        {
            ans += '(';
            DFS(root->right);
            ans += ')';
        }
    }
    
    string tree2str(TreeNode* root) {
        DFS(root);
        return ans;
    }
};