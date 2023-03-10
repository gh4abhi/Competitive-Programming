// Problem Link - https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
#define ll int
class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    ll DFS(Node* root)
    {
        if(root->left==nullptr and root->right==nullptr)
        {
            ll val = root->data;
            root->data = 0;
            return val;
        }
        ll lef = 0, righ = 0;
        if(root->left)
            lef = DFS(root->left);
        if(root->right)
            righ = DFS(root->right);
        ll sum = root->data + lef + righ;
        root->data = lef+righ;
        return sum;
    }
    
    void toSumTree(Node *node)
    {
        DFS(node);
    }
};