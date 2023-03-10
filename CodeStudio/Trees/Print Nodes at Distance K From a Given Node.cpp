// Problem Link - https://www.codingninjas.com/codestudio/problems/print-nodes-at-distance-k-from-a-given-node_842560?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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
void makePar(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>& par, BinaryTreeNode<int>* root)
    {
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        while(q.size())
        {
            BinaryTreeNode<int>* cur = q.front();
            q.pop();
            if(cur->left)
                par[cur->left] = cur, q.push(cur->left);
            if(cur->right)
                par[cur->right] = cur, q.push(cur->right);
        }
    }
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k) {
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> par;
        vector<BinaryTreeNode<int>*> ans;
        makePar(par,root);
        queue<BinaryTreeNode<int>*> q;
        q.push(target);
        BinaryTreeNode<int>* dummy = new BinaryTreeNode<int>(-1);
        ll level = 0;
        q.push(dummy);
        if(k==0)
        {
            ans.push_back(q.front());
            return ans;
        }
        map<BinaryTreeNode<int>*,ll> vis;
        while(q.size())
        {
            BinaryTreeNode<int>* cur = q.front();
            q.pop();
            if(cur->data==-1)
            {
                if(q.size()==0)
                    break;
                if(++level==k)
                    break;
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
        while(q.size())
            ans.push_back(q.front()), q.pop();
        return ans;
}