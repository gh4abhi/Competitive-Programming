// Problem Link - https://www.codingninjas.com/codestudio/problems/794950?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
ll DFS(TreeNode<int> *root, ll &ans)
{
    if(root==nullptr)
        return 0;
    ll lef = max(0ll,DFS(root->left,ans));
    ll rig = max(0ll,DFS(root->right,ans));
    ans = max(ans,root->val+lef+rig);
    return root->val + max(lef,rig);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if(root==nullptr or root->left==nullptr or root->right==nullptr)
        return -1;
    ll ans = 0;
    DFS(root,ans);
    return ans;
}