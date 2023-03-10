// Problem Link - https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    
    ll count = 0;
    
    void DFS(TreeNode* root, ll maxVal)
    {
        if(root==nullptr)
            return;
        if(root->val>=maxVal)
            maxVal = root->val,count+=1;
        DFS(root->left,maxVal);
        DFS(root->right,maxVal);
    }
    
    int goodNodes(TreeNode* root) {
        DFS(root,-10001);
        return count;
    }
};