// Problem Link - https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

#define ll int

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void DFS(Node* root, map<ll,vector<ll>>& adj)
    {
        if(root==nullptr)
            return;
        if(root->left)
        {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
            DFS(root->left,adj);
        }
        if(root->right)
        {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
            DFS(root->right,adj);
        }
    }
    int findDist(Node* root, int a, int b) {
        map<ll,vector<ll>> adj;
        DFS(root,adj);
        map<ll,ll> dis;
        map<ll,ll> vis;
        queue<ll> q;
        q.push(a);
        dis[a] = 0;
        vis[a] = 1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            for(auto i:adj[cur])
            {
                if(vis.count(i)==0)
                {
                    vis[i] = 1;
                    dis[i] = dis[cur] + 1;
                    q.push(i);
                }
                else
                    dis[i] = min(dis[i],dis[cur]  +1);
            }
        }
    return dis[b];
    }
};