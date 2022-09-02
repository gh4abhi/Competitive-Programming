// Problem Link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode* dummy = nullptr;
        q.push(root);
        double sum = 0;
        double count = 0;
        q.push(dummy);
        vector<double> ans;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==nullptr)
            {
                double op = (sum)/(count);
                ans.push_back(op);
                sum = 0;
                count = 0;
                if(q.size()==0)
                    break;
                q.push(dummy);
                continue;
            }
            sum+=cur->val;
            count+=1;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return ans;
    }
};