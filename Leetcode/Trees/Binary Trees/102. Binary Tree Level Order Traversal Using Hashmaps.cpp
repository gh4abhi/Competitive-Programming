//Problem Link - https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==nullptr)
    {
        return vector<vector<int>>();
    }
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        pair<TreeNode*,int> temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp.first->left)
            {
                q.push(make_pair(temp.first->left,temp.second+1));
            }
            if(temp.first->right)
            {
                q.push(make_pair(temp.first->right,temp.second+1));
            }
            if(ans.size()==temp.second)
            {
                ans.push_back(vector<int>());
            }
            ans[temp.second].push_back(temp.first->val);
        }
        return ans;
    }
};
