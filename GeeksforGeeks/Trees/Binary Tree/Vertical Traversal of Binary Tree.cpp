// Problem Link - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/?page=1&difficulty[]=1&status[]=unsolved&sortBy=submissions#

#define ll int
class Solution{
    public:
    map<pair<ll,ll>,vector<ll>> m;
    
    void DFS(Node* root, ll col,ll row)
    {
        if(root==nullptr)
            return;
        m[{col,row}].push_back(root->data);
        DFS(root->left,col-1,row+1);
        DFS(root->right,col+1,row+1);
    }
    
    vector<int> verticalOrder(Node *root)
    {
        vector<ll> ans;
        DFS(root,0,0);
        for(auto i:m)
            for(auto j:i.second)
                ans.push_back(j);
        return ans;
    }
};