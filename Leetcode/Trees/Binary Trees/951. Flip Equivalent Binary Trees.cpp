// Problem Link - https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    
    bool DFS(TreeNode* root1, TreeNode* root2)
    {
        if(root1==nullptr and root2==nullptr)
            return true;
        if(root1==nullptr or root2==nullptr)
            return false;
        if(root1->val!=root2->val)
            return false;
        bool op1 = DFS(root1->left,root2->left) and DFS(root1->right,root2->right); 
        bool op2 = DFS(root1->right,root2->left) and DFS(root1->left,root2->right);
        return op1 or op2;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return DFS(root1,root2);
    }
};