// Problem Link - https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void changeTree(BinaryTreeNode < int > * root) {
    if(root==nullptr)
        return;
    ll sum = 0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;
    if(sum>=root->data)
        root->data = sum;
    else
    {
        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    sum = 0;
    if(root->left)
        sum+=root->left->data;
    if(root->right)
        sum+=root->right->data;
    if(root->left or root->right)
        root->data = sum;
}  