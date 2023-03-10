// Problem Link - https://leetcode.com/contest/weekly-contest-324/problems/add-edges-to-make-degrees-of-all-nodes-even/

#define ll int

class Solution {
public:
    
    void DFS(ll src, vector<ll> &op, ll &count, map<ll,map<ll,ll>> &adj, map<ll,ll> &vis)
    {
        vis[src] = 1;
        op.push_back(src);
        count += 1;
        for(auto i:adj[src])
            if(vis.count(i.first)==0)
                DFS(i.first,op,count,adj,vis);
    }
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<ll> ok;
        map<ll,map<ll,ll>> adj;
        map<ll,ll> vis;
        map<ll,ll> deg;
        for(auto i:edges)
            adj[i[0]][i[1]]++, adj[i[1]][i[0]]++, deg[i[1]]++, deg[i[0]]++;
        vector<vector<ll>> op;
        for(ll i=1;i<=n;i++)
        {
            if(vis.count(i)==0)
            {
                vector<ll> check;
                ll count = 0;
                DFS(i,check,count,adj,vis);
                op.push_back(check);
                ok.push_back(count);
            }
        }
        if(ok.size()==1 and ok[0]%2==0)
        {
            for(auto j:op[0])
                if(deg[j]==ok[0]-1)
                    return false;
        }
        ll c = 0;
        ll ed = 2;
        vector<ll> res;
        for(ll i=0;i<ok.size();i++)
        {
            for(auto j:op[i])
            {
                if(deg[j]&1)
                    res.push_back(j);
            }
        }
        ll start = 0, end = res.size()-1;
        map<ll,ll> l;
        while(start<res.size())
        {
            end = res.size()-1;
            if(l.count(res[start]))
            {
                start++;
                continue;
            }
            if(ed==0)
                return false;
            while(end>start and (adj[res[start]].count(res[end]) or l.count(res[end])))
                end--;
            l[res[end]] = 1;
            l[res[start]] = 1;
            start++;
            ed--;
        }
        return true;
    }
};