// Problem Link - https://leetcode.com/problems/balanced-binary-tree/

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
    
    pair<ll,bool>isBalancedHelper(TreeNode* root)
{
    ll curHeight = 0;
    pair<ll,bool> lef, righ;
    lef.first = 0;
    lef.second = true;
    righ.first = 0;
    righ.second = true;
    bool curCheck = true;
    if(root)
    {
        curHeight=1;
        if(root->left)
        {
            lef = isBalancedHelper(root->left);
        }
        if(root->right)
        {
            righ = isBalancedHelper(root->right);
        }
    }
    ll tempCheck = abs(lef.first-righ.first);
    if(tempCheck>1)
    {
        curCheck = false;
    }

    curCheck = curCheck and lef.second and righ.second;
    curHeight = max(curHeight+lef.first,curHeight+righ.first);
    return make_pair(curHeight,curCheck);
}
    
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).second;
    }
};
