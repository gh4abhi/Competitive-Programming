// Problem Link - https://www.codingninjas.com/codestudio/problems/796002?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<ll> ans;
    queue<BinaryTreeNode<int> *> q;
    if(root==nullptr)
        return ans;
    q.push(root);
    while(q.size())
    {
        BinaryTreeNode<int> * cur = q.front();
        q.pop();
        ans.push_back(cur->val);
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
    return ans;
}