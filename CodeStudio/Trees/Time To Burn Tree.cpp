// Problem Link - https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* makePar(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>& par, BinaryTreeNode<int>* root,ll start)
    {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        BinaryTreeNode<int>* target;
        while(q.size())
        {
            BinaryTreeNode<int>* cur = q.front();
            q.pop();
            if(cur->data==start)
                target = cur;
            if(cur->left)
                par[cur->left] = cur, q.push(cur->left);
            if(cur->right)
                par[cur->right] = cur, q.push(cur->right);
        }
    return target;
    }
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> par;
        vector<BinaryTreeNode<int>*> ans;
        BinaryTreeNode<int>* target = makePar(par,root,start);
        queue<BinaryTreeNode<int>*> q;
        q.push(target);
        BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(-1);
        ll level = 0;
        q.push(dummy);
        map<BinaryTreeNode<int>*,ll> vis;
        while(q.size())
        {
            BinaryTreeNode<int>* cur = q.front();
            q.pop();
            if(cur->data==-1)
            {
                if(q.size()==0)
                    break;
                level++;
                q.push(dummy);
                continue;
            }
            vis[cur] = 1;
            if(cur->left and !vis.count(cur->left))
                q.push(cur->left);
            if(cur->right and !vis.count(cur->right))
                q.push(cur->right);
            if(par.count(cur) and !vis.count(par[cur]))
                q.push(par[cur]);
        }
        return level;
}
