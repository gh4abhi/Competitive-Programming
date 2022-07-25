// Problem Link - https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map<ll,map<ll,vector<ll>>> m;
    queue<pair<TreeNode<ll>*,pair<ll,ll>>> q;
    q.push({root,{0,0}});
    while(q.size())
    {
        auto p = q.front();
        ll c = p.second.first;
        ll r = p.second.second;
        TreeNode<ll>* cur = p.first;
        q.pop();
        m[c][r].push_back(cur->data);
        if(cur->left)
            q.push({cur->left,{c-1,r+1}});
        if(cur->right)
            q.push({cur->right,{c+1,r+1}});
    }
    vector<ll> ans;
    for(auto i:m)
        for(auto j:i.second)
            ans.insert(ans.end(),j.second.begin(),j.second.end());
    return ans;
}