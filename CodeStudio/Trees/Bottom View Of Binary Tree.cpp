// Problem Link - https://www.codingninjas.com/codestudio/problems/893110?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<ll> ans;
    if(root==nullptr)
        return ans;
    map<ll,ll> m;
    queue<pair<ll,BinaryTreeNode<ll>*>> q;
    q.push({0,root});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        m[cur.first] = cur.second->data;
        if(cur.second->left)
            q.push({cur.first-1,cur.second->left});
        if(cur.second->right)
            q.push({cur.first+1,cur.second->right});
    }
    for(auto i:m)
        ans.push_back(i.second);
    return ans;
}
