// Problem Link - https://www.codingninjas.com/codestudio/problems/maximum-width-in-binary-tree_763671?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root==nullptr)
        return 0;
    ll ans = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size())
    {
        ll sz = q.size();
        ans = max(ans,sz);
        for(ll i=0;i<sz;i++)
        {
            TreeNode<int>* cur = q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return ans;
}