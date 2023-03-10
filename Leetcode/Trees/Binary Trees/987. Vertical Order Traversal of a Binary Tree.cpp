// Problem Link -https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<pair<ll,ll>,priority_queue<ll,vector<ll>, greater<ll>>> ans;
    
    void verticalTraversalHelper(TreeNode* root, ll row, ll col)
    {
        ans[make_pair(col,row)].push(root->val);
        if(root->left)
            verticalTraversalHelper(root->left, row+1, col-1);
        if(root->right)
            verticalTraversalHelper(root->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> arr;
        map<ll,vector<ll>> temp;
        verticalTraversalHelper(root, 0,0);
        for(auto i:ans)
        {
            while(i.second.size())
            {
                temp[i.first.first].push_back(i.second.top());
                i.second.pop();
            }
        }
        
        for(auto i:temp)
        {
            vector<ll> t;
            for(auto j:i.second)
                t.push_back(j);
            arr.push_back(t);
        }
        return arr;
    }
};