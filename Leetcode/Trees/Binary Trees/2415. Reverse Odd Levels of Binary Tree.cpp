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
        stack<ll> st;
        q.push(root);
        q.push(nullptr);
        ll level = 0;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==nullptr)
            {
                if(q.size()==0)
                    break;
                level+=1;
                q.push(nullptr);
                continue;
            }
            if(level&1)
                cur->val = st.top(), st.pop();
            if(cur->left)
            {
                if(!(level&1))
                    st.push(cur->left->val);
                q.push(cur->left);
            }
            if(cur->right)
            {
                if(!(level&1))
                    st.push(cur->right->val);
                q.push(cur->right);
            }
        }
        return root;
    }
};