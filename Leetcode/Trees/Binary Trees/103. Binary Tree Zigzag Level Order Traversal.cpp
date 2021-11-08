// Problem Link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>pendingNodes;
        if(root)
        {
            ll flag = 1;
            pendingNodes.push(root);
            while(pendingNodes.size()!=0)
            {
                ll size = pendingNodes.size();
                vector<ll> temp;
                flag = !flag;
                for(ll i=0;i<size;i++)
                {
                    TreeNode* current = pendingNodes.front();
                    pendingNodes.pop();
                    temp.push_back(current->val);
                    if(current->left)
                    {
                        pendingNodes.push(current->left);
                    }
                    if(current->right)
                    {
                        pendingNodes.push(current->right);
                    }
                }
                if(flag==1)
                {
                    reverse(temp.begin(),temp.end());
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
