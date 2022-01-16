// Problem Link - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#define ll int

class Solution {
public:
    
    ll maxAncestorDiffHelper(TreeNode*root, ll maxi, ll mini)
    {
        ll ans = INT_MIN;
        ans = max(ans,abs(root->val-maxi));
        ans = max(ans,abs(root->val-mini));
        maxi = max(root->val,maxi);
        mini = min(root->val,mini);
        if(root->left)
            ans = max(ans,maxAncestorDiffHelper(root->left, maxi,mini));
        if(root->right)
            ans = max(ans,maxAncestorDiffHelper(root->right,maxi,mini));
        return ans;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(root)
        return maxAncestorDiffHelper(root,root->val,root->val);
        return 0;
    }
};
