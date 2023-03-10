// Problem Link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

#define ll int
class Solution {
public:
    vector<ll> ans;
    void leftBoundary(Node* root)
    {
        if((root==nullptr))
        return;
        if((root->left==nullptr and root->right==nullptr))
            return;
        ans.push_back(root->data);
        if(root->left)
            leftBoundary(root->left);
        else
            leftBoundary(root->right);
    }
    
    void bottomBoundary(Node* root)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr and root->right==nullptr)
            ans.push_back(root->data);
        bottomBoundary(root->left);
        bottomBoundary(root->right);
    }
    vector<ll> temp;
    void rightBoundary(Node* root)
    {
        if((root==nullptr))
            return;
        if((root->left==nullptr and root->right==nullptr))
            return;
        if(root->right)
            rightBoundary(root->right);
        else
            rightBoundary(root->left);
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        if(root==nullptr)
            return ans;
        ans.push_back(root->data);
        if(root->left==nullptr and root->right==nullptr)
            return ans;
        leftBoundary(root->left);
        bottomBoundary(root);
        rightBoundary(root->right);
        return ans;
    }
};