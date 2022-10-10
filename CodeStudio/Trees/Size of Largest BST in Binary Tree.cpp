// Problem Link - https://www.codingninjas.com/codestudio/problems/893103?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
/************************************************************

    Following is the Binary Tree node structure
    
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

class node{
    public:
    ll maxi, mini,sum;

    node(ll maxi,ll mini,ll sum)
    {
        this->maxi = maxi;
        this->mini = mini;
        this->sum = sum;
    }
};

node post(TreeNode<ll>* root)
{
    if(root==nullptr)
        return node(INT_MIN,INT_MAX,0);
    auto lef = post(root->left);
    auto rig = post(root->right);
    if(root->data>lef.maxi and root->data<rig.mini)
        return node(max(rig.maxi,root->data), min(lef.mini,root->data), lef.sum + rig.sum + 1);
    return node(INT_MAX,INT_MIN,max(lef.sum,rig.sum));
}

int largestBST(TreeNode<int>* root) 
{
    return post(root).sum;
}
