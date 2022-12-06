// Problem Link - https://practice.geeksforgeeks.org/problems/k-distance-from-root/1?page=2&company[]=Microsoft&category[]=Tree&sortBy=submissions

void DFS(Node* root, ll level, ll k, vector<ll> &ans)
{
    if(root==nullptr)
        return;
    if(level==k)
        ans.push_back(root->data);
    DFS(root->left,level+1,k,ans);
    DFS(root->right,level+1,k,ans);
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<ll> ans;
    DFS(root,0,k,ans);
    return ans;
}