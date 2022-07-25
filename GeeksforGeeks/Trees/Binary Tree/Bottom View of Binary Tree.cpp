// Problem Link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#define ll int

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<ll> ans;
        if(root==nullptr)
            return ans;
        queue<pair<ll,Node*>> q;
        map<ll,ll> m;
        q.push({0,root});
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
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