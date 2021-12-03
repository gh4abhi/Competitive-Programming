// Problem Link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#define ll int
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    map<ll,vector<ll>> m;
    vector<ll>  vect;
    map<ll,ll> visited;
    void buildGraph(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                m[root->val].push_back(root->left->val);
                m[root->left->val].push_back(root->val);
                buildGraph(root->left);
            }
            if(root->right)
            {
                m[root->val].push_back(root->right->val);
                m[root->right->val].push_back(root->val);
                buildGraph(root->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root);
        queue<pair<ll,ll>> pendingNodes;
        ll level = 0;
        pendingNodes.push(make_pair(target->val,level));
        visited[target->val]++;
        while(pendingNodes.size()!=0)
        {
            pair<ll,ll> current = pendingNodes.front();
            pendingNodes.pop();
            cout<<current.first<<" "<<current.second<<endl;
            level = current.second;
            if(current.second==k)
            {
                vect.push_back(current.first);
            }
            for(auto i:m[current.first])
            {
                if(visited.count(i)==0)
                {
                    pendingNodes.push(make_pair(i,level+1));
                    visited[i]++;
                }
            }
        }
        return vect;
    }
};
