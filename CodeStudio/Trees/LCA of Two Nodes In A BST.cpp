// Problem Link - https://www.codingninjas.com/codestudio/problems/981280?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

TreeNode<int>* DFS(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
    if(root==nullptr)
        return nullptr;
    if(p->data<root->data and q->data<root->data)
        return DFS(root->left,p,q);
    if(p->data>root->data and q->data>root->data)
        return DFS(root->right,p,q);
    return root;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    return DFS(root,P,Q);
}
