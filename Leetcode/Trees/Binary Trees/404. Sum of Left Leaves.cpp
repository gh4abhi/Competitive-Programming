// Problem Link - https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumofLeftLeavesHelper(root,0);
    }
    
      int sumofLeftLeavesHelper(TreeNode* root, int flag)
    {
        int sum = 0;
        if(root->left==nullptr and root->right==nullptr and flag==1)
        {
            sum += root->val;
            return sum;
        }
          if(root->left)
          sum+= sumofLeftLeavesHelper(root->left, 1);
          if(root->right)
              sum+= sumofLeftLeavesHelper(root->right, 0);
          return sum;
    }
};
