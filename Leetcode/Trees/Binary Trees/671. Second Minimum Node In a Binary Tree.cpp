// Problem Link - https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    set<ll> s;
    set<ll>:: iterator it;
    int findSecondMinimumValue(TreeNode* root) {
    findSecondMinimumValueHelper(root);
    it = s.begin(); 
        ll a = -1;
       
        if(s.size()>=2)
        {
            it++;
             a = *it;    
        }
        return a;
    }
    void findSecondMinimumValueHelper(TreeNode* root)
    {
        if(root)
      {
          s.insert(root->val);
      }
      if(root->left)
      {
          findSecondMinimumValueHelper(root->left);
      }
       if(root->right)
      {
          findSecondMinimumValueHelper(root->right);
      } 
    }
};
