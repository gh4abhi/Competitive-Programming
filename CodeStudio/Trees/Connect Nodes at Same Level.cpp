// Problem Link - https://www.codingninjas.com/codestudio/problems/985347?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    q.push(nullptr);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        if(cur==nullptr)
        {
            if(q.size()==0)
                break;
            q.push(nullptr);
            continue;
        }
        cur->next = q.front();
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
}