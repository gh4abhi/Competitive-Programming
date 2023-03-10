// Problem Link - https://leetcode.com/problems/minimum-genetic-mutation/

#define ll int

class Solution {
public:
    
    ll ans = INT_MAX;
    
    void DFS(string src, vector<string> &bank, string end, unordered_map<string,ll> &vis, ll dis)
    {
        vis[src] = 1;
        if(src==end)
        {
            ans = min(ans,dis);
            return;
        }
        for(ll i=0;i<src.length();i++)
        {
            char op = src[i];
            for(char ch = 'A'; ch<='Z';ch++)
            {
                src[i] = ch;
                ll flag = 0;
                for(auto k:bank)
                    if(k==src)
                        flag = 1;
                if(flag and vis[src]==0)
                    DFS(src,bank,end,vis,dis+1);
            }
            src[i] = op;
        }
        vis[src] = 0;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,ll> vis;
        DFS(start,bank,end,vis,0);
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};