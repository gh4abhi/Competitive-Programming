// Problem Link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> pendingNodes;
        vector<vector<int>> vect;
        if(root)
        {
            pendingNodes.push(root);
        }
        while(pendingNodes.size()!=0)
        {
            vector<int> v;
            int s = pendingNodes.size();
            for(int i=0;i<s;i++)
            {
            TreeNode* current = pendingNodes.front();
            pendingNodes.pop();
                v.push_back(current->val);
                if(current->left)
                {
                    pendingNodes.push(current->left);
                }
                if(current->right)
                {
                    pendingNodes.push(current->right);
                }
            }
            vect.push_back(v);
        }
        reverse(vect.begin(),vect.end());
        return vect;
    }
};
