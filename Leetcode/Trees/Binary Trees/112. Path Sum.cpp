// Problem Link - https://leetcode.com/problems/path-sum/

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
    vector<int> vect;
    int r=0,l=0,ri=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            r+=root->val;
        haspathSumHelper(root,r,0,0);
        if(find(vect.begin(),vect.end(),targetSum)!=vect.end())
        {
            return true;
        }
        }
        return false;
    }
    
    void haspathSumHelper(TreeNode* root,int r,int l,int ri)
    {
        l = ri = r;
        if(root->left==nullptr and root->right==nullptr)
        {
            vect.push_back(r);
            return;
        }
        if(root->left)
        {
            l+=root->left->val;
            haspathSumHelper(root->left,l,0,0);
        }
        if(root->right)
        {
            ri+=root->right->val;
            haspathSumHelper(root->right,ri,0,0);
        }
    }
};
