// Problem Link - https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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
    
    vector<ll> DFS(TreeNode* root, ll distance, ll &ans)
    {
        if(root==nullptr)
            return {};
        if(!root->left and !root->right)
            return {1};
        auto lef = DFS(root->left,distance,ans);
        auto rig = DFS(root->right,distance,ans);
        for(auto i:lef)
            for(auto j:rig)
                if(i+j<=distance)
                    ans+=1;
        vector<ll> op;
        for(auto i:lef)
            op.push_back(i+1);
        for(auto i:rig)
            op.push_back(i+1);
        return op;
    }
    
    int countPairs(TreeNode* root, int distance) {
        ll ans = 0;
        DFS(root,distance,ans);
        return ans;
    }
};