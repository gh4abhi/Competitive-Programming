// Problem Link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbersHelper(TreeNode*root, string str)
    {
        
        int lsum = 0,rsum=0;
        if(root->left)
        {
        string lstr = str + to_string(root->left->val);    
         lsum = sumNumbersHelper(root->left, lstr);
        }
        if(root->right)
        {
        string rstr = str + to_string(root->right->val);
        rsum = sumNumbersHelper(root->right, rstr);
        }
        if(root->left==nullptr and root->right==nullptr)
        {
            stringstream leet(str);
            leet>>lsum;
        }
        return (lsum+rsum);
    }
    int sumNumbers(TreeNode* root) {
        if(root)
        {
         string str = to_string(root->val);
        return sumNumbersHelper(root,str);
        }
        else
        {
            return 0;
        }
        }
};
