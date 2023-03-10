// Problem Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/

#define ll long long
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
    int maxDepth(TreeNode* root) {
        if(root)
        {
        ll height = 1;
        ll k1 = 1,k2=1;
            k1+=maxDepth(root->left);
            k2+=maxDepth(root->right);
            height = max(max(k1,k2),height);
            return height;
        }
        else
        {
            return 0;
        }
    }
};
