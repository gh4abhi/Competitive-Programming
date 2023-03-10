// Problem Link - https://leetcode.com/problems/combinations/

#define ll int

class Solution {
public:
    
    void DFS(ll ind, vector<vector<ll>> &ans, vector<ll> &ds, ll k, ll n)
    {
        if(ds.size()==k)
        {
            ans.push_back(ds);
            return;
        }
        for(ll i=ind;i<=n;i++)
        {
            ds.push_back(i);
            DFS(i+1,ans,ds,k,n);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<ll>> ans;
        vector<ll> ds;
        DFS(1,ans,ds,k,n);
        return ans;
    }
};