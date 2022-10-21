// Problem Link - https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root) {
        if(root==nullptr)
            return true;
        stack<TreeNode*> st1;
        st1.push(root);
        stack<TreeNode*> st2;
        if(root->val%2==0)
            return false;
        while(st1.size() or st2.size())
        {
            ll pre = -1;
            while(st1.size())
            {
                auto cur = st1.top();
                st1.pop();
                if(cur->val<=pre)
                    return false;
                if(cur->left)
                {
                    if(cur->left->val&1)
                        return false;
                    st2.push(cur->left);
                }
                if(cur->right)
                {
                    if(cur->right->val&1)
                        return false;
                    st2.push(cur->right);
                }
                pre = cur->val;
            }
            pre = -1;
            while(st2.size())
            {
                auto cur = st2.top();
                st2.pop();
                if(cur->val<=pre)
                    return false;
                if(cur->right)
                {
                    if(cur->right->val%2==0)
                        return false;
                    st1.push(cur->right);
                }
                if(cur->left)
                {
                    if(cur->left->val%2==0)
                        return false;
                    st1.push(cur->left);
                }
                pre = cur->val;
            }
        }
        return true;
    }
};