// Problem Link - https://leetcode.com/contest/weekly-contest-319/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root==nullptr)
            return 0;
        vector<vector<pair<ll,ll>>> op;
        vector<pair<ll,ll>> vect;
        q.push(nullptr);
        ll k = 0;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur==nullptr)
            {
                op.push_back(vect);
                vect.clear();
                if(q.size()==0)
                    break;
                q.push(nullptr);
                k=0;
                continue;
            }
            vect.push_back({cur->val,k++});
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        for(auto &i:op)
            sort(i.begin(),i.end());
        ll ans = 0;
        for(ll i=0;i<op.size();i++)
        {
            for(ll j=0;j<op[i].size();j++)
            {
                if(j!=op[i][j].second)
                {
                    ans++;
                    swap(op[i][op[i][j].second],op[i][j]);
                    j--;
                }
            }
        }
        return ans;
    }
};