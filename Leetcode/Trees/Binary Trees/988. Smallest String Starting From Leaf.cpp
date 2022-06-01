// Problem Link - https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    
    vector<string>ans;
    
    void DFS(TreeNode* root, string str)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
        {
            char ok = 'a'+root->val;
            str += ok;
            reverse(str.begin(),str.end());
            ans.push_back(str);
            return;
        }
        char op = 'a'+root->val;
        DFS(root->left,str+(op));
        DFS(root->right,str+(op));
    }
    
    string smallestFromLeaf(TreeNode* root) {
        DFS(root,"");
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};