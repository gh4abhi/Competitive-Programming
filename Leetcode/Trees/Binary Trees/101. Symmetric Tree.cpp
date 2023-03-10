// Problem Link - https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetricHelper(TreeNode*Tree1, TreeNode*Tree2)
    {
        if(Tree1==nullptr and Tree2==nullptr)
        {
            return true;
        }
        else if((Tree1==nullptr and Tree2)or(Tree2==nullptr and Tree1))
        {
            return false;
        }
       else if(Tree1->val==Tree2->val)
       {
           return isSymmetricHelper(Tree1->left,Tree2->right) and isSymmetricHelper(Tree2->left,Tree1->right);
       }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root)
        {
            if(root->left==nullptr and root->right== nullptr)
            {
                return true;
            }
      return isSymmetricHelper(root->left, root->right); 
        }
        return false;
    }
};
