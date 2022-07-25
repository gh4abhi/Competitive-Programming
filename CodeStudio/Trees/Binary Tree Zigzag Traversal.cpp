// Problem Link - https://www.codingninjas.com/codestudio/problems/1062662?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> st1,st2;
    st1.push(root);
    vector<ll> ans;
    if(root==nullptr)
        return ans;
    while(st1.size() or st2.size())
    {
        while(st1.size())
        {
            BinaryTreeNode<ll>* cur = st1.top();
            st1.pop();
            if(cur->left)
                st2.push(cur->left);
            if(cur->right)
                st2.push(cur->right);
            ans.push_back(cur->data);
        }
        while(st2.size())
        {
            BinaryTreeNode<ll>* cur = st2.top();
            st2.pop();
            if(cur->right)
                st1.push(cur->right);
            if(cur->left)
                st1.push(cur->left);
            ans.push_back(cur->data);
        }
    }
    return ans;
}
