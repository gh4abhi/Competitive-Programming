// Problem Link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#define ll int
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        map<ll,ll> m;
        vector<ll> ans;
        if(root==nullptr)
            return ans;
        queue<pair<ll,Node*>> q;
        q.push({0,root});
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(!m.count(cur.first))
                m[cur.first] = cur.second->data;
            if(cur.second->left)
                q.push({cur.first-1,cur.second->left});
            if(cur.second->right)
                q.push({cur.first+1,cur.second->right});
        }
        for(auto i:m)
            ans.push_back(i.second);
        return ans;
    }

};
