// Problem Link - https://www.codingninjas.com/codestudio/problems/height-of-spiral-tree_977248?leftPanelTab=0

#include <bits/stdc++.h> 
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

ll DFS(BinaryTreeNode<ll>* root, BinaryTreeNode<ll>* node)
{
    if(root==nullptr)
        return 0;
    if(root->left==node and root->right->left==root)
        return 1;
    ll lef = DFS(root->left,root);
    ll rig = DFS(root->right,root);
    return 1 + max(lef,rig);
}

int findHeight(BinaryTreeNode<int>* root) {
    return DFS(root,root);
}