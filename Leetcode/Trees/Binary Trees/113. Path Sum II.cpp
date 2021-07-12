// Problem Link  - https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> ans;
    vector<int> vectl,vectr,vect;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
        {
            vect.push_back(root->val);
            pathSumHelper(root,vect,vectl,vectr,targetSum);
        }
        return ans;
    }
    
    void pathSumHelper(TreeNode* root, vector<int> vect, vector<int> vectl, vector<int> vectr, int targetSum)
    {
        vector<int> vl,vr;
        vectl = vectr = vect;
        if(root->left == nullptr and root->right == nullptr)
        {
            int sum = accumulate(vect.begin(),vect.end(),0);
            if(sum==targetSum)
            {
                ans.push_back(vect);
            }
            return;
        }
        if(root->left)
        {
            vectl.push_back(root->left->val);
            pathSumHelper(root->left, vectl, vl ,vr, targetSum);
        }
        if(root->right)
        {
            vectr.push_back(root->right->val);
            pathSumHelper(root->right, vectr, vl ,vr, targetSum);
        }
    }
};
