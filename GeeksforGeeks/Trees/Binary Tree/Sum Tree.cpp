// Problem Link - https://practice.geeksforgeeks.org/problems/sum-tree/1/?page=2&difficulty[]=1&sortBy=submissions#

class Solution
{
    public:
    
    bool check = true;
    
    ll DFS(Node* root)
    {
        if(root->left==nullptr and root->right==nullptr)
            return root->data;
        ll lef = 0, righ = 0;
        if(root->left)
            lef = DFS(root->left);
        if(root->right)
            righ = DFS(root->right);
        if(root->data!=(lef+righ))
            check = false;
        ll sum = root->data + lef + righ;
        return sum;
    }
    
    bool isSumTree(Node* root)
    {
        DFS(root);
        return check;
    }
};