// Problem Link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr)
            return -1;
        queue<TreeNode*> q;
        q.push(root);
        ll level = 1;
        q.push(nullptr);
        ll maxi = INT_MIN;
        ll ans = -1;
        ll sum = 0;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==nullptr)
            {
                if(maxi<sum)
                    maxi = sum, ans = level;
                level+=1;
                sum = 0;
                if(q.size()==0)
                    break;
                q.push(nullptr);
                continue;
            }
            sum += cur->val;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return ans;
    }
};