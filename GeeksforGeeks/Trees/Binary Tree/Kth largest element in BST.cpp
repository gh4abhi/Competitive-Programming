// Problem Link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

#define ll int
// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    ll ans = -1;
    void DFS(Node* root, ll k, ll &op)
    {
        if(root==nullptr)
            return;
        DFS(root->right,k,op);
        op+=1;
        if(op==k)
            ans = root->data;
        DFS(root->left,k,op);
    }
    
    int kthLargest(Node *root, int K)
    {
        ll op =0 ;
        DFS(root,K,op);
        return ans;
    }
};