// Problem Link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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
    
    ll maxSum = INT_MIN;
    vector<ll> maxSumBSTHelper(TreeNode* root)
    {
      vector<ll> vect(4);
      if(root->left==nullptr and root->right==nullptr)
      {
          vect[0] = root->val;
          vect[1] = root->val;
          vect[2] = root->val;
          vect[3] = 1;
          maxSum = max(root->val,maxSum);
          return vect;  
      }
        
        ll lFlag = 1, rFlag = 1, lSum = 0, rSum = 0, lMaxi = INT_MIN, lMini = INT_MAX, rMaxi = INT_MIN, rMini = INT_MAX;
        
        vector<ll> forLeft(4), forRight(4);
        forLeft[3] = 1;
        forRight[3] = 1;
        if(root->left)
        {
            forLeft = maxSumBSTHelper(root->left);
            lSum = forLeft[0];
            lMaxi = forLeft[1];
            lMini = forLeft[2];
            lFlag = forLeft[3];
        }
        
        if(root->right)
        {
            forRight = maxSumBSTHelper(root->right);
            rSum = forRight[0];
            rMaxi = forRight[1];
            rMini = forRight[2];
            rFlag = forRight[3];
        }
        cout<<root->val<<" "<<lMini<<" "<<lMaxi<<" "<<rMaxi<<" "<<rMini<<" "<<rFlag<<" "<<lFlag<<endl;
        if(!rFlag or !lFlag)
        {
            return vect;
        }
        
        if(root->val>lMaxi and root->val<rMini)
        {
            vect[0] = lSum + rSum + root->val;
            vect[1] = max(root->val,rMaxi);
            vect[2] = min(root->val,lMini);
            vect[3] = 1;
            maxSum = max(maxSum, vect[0]);
            return vect;
        }
        return vect;
    }
    
    int maxSumBST(TreeNode* root) {
        vector<ll> vect = maxSumBSTHelper(root);
        return max(maxSum,0);
    }
};
