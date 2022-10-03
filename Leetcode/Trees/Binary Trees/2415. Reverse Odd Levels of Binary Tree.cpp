// Problem Link - https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        ll level = 0;
        vector<TreeNode*> vect;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==nullptr)
            {
                if(level&1)
                {
                    ll start = 0, end = vect.size()-1;
                    while(start<end)
                        swap(vect[start]->val,vect[end]->val), start+=1, end-=1;
                }
                if(q.size()==0)
                    break;
                level+=1;
                q.push(nullptr);
                vect.clear();
                continue;
            }
            vect.push_back(cur);
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        return root;
    }
};