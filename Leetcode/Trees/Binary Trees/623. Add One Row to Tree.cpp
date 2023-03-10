// Problem Link - https://leetcode.com/problems/add-one-row-to-tree/

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
    
    void DFS(TreeNode* root, ll val, ll d, ll depth)
    {
        if(root==nullptr)
            return;
        if(d==depth-1)
        {
            TreeNode* lef = root->left;
            TreeNode* rig = root->right;
            TreeNode* a = new TreeNode(val);
            root->left = a;
            a->left = lef;
            TreeNode* b = new TreeNode(val);
            root->right = b;
            b->right = rig;
            return;
        }
        DFS(root->left,val,d+1,depth);
        DFS(root->right,val,d+1,depth);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        DFS(root,val,1,depth);
        return root;
    }
};