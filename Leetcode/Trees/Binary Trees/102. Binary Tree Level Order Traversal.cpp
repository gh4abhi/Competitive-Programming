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
     vector<vector<int>> vect;
    queue<TreeNode*> pendingNodes;
        if(root!=nullptr)
        {
        pendingNodes.push(root);
        while(pendingNodes.size()!=0)
        {
            vector<int> v;
            int count = pendingNodes.size();
            for(int i=0;i<count;i++)
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
            if(v.size()!=0)
            vect.push_back(v);
        }
        }
        return vect;
        
    }
};
