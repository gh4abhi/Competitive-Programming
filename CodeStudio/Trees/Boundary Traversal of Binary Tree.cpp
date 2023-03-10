// Problem Link - https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void addLeft(TreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    TreeNode<ll>* cur = root->left;
    while(cur)
    {
        if(cur->left or cur->right)
            ans.push_back(cur->data);
        if(cur->left)
            cur = cur->left;
        else 
            cur = cur->right;
    }
}

void addLeaves(TreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    addLeaves(root->left,ans);
    if(root->left==nullptr and root->right==nullptr)
        ans.push_back(root->data);
    addLeaves(root->right,ans);
}

void addRight(TreeNode<ll>* root, vector<ll>& ans)
{
    if(root==nullptr)
        return;
    TreeNode<ll>* cur = root->right;
    vector<ll>temp;
    while(cur)
    {
        if(cur->left or cur->right)
            temp.push_back(cur->data);
        if(cur->right)
            cur = cur->right;
        else 
            cur = cur->left;
    }
    for(ll i=temp.size()-1;i>=0;i--)
        ans.push_back(temp[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<ll> ans;
    if(root==nullptr)
        return ans;
    if(root->left or root->right)
        ans.push_back(root->data);
    addLeft(root,ans);
    addLeaves(root,ans);
    addRight(root,ans);
    return ans;
}