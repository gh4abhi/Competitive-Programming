// Problem Link - https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        ll ans = 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        while(q.size())
        {
            ll sz = q.size();
            ll mini = q.front().second;
            ll first, last;
            for(ll i=0;i<sz;i++)
            {
                pair<TreeNode*,ll> cur = q.front();
                q.pop();
                if(i==0)
                    first = cur.second-mini;
                if(i==sz-1)
                    last = cur.second-mini;
                if(cur.first->left)
                    q.push({cur.first->left,(2*(cur.second-mini)+1)});
                if(cur.first->right)
                    q.push({cur.first->right,(2*(cur.second-mini)+2)});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};