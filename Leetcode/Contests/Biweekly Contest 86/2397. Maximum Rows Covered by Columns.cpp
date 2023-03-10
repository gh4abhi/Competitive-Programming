// Problem Link - https://leetcode.com/problems/maximum-rows-covered-by-columns/

#define ll int

class Solution {
public:
    map<pair<pair<vector<ll>,vector<ll>>,ll>,ll> dp;
    ll maxRow(vector<vector<ll>> &vect, ll ans, vector<ll>& vis,ll c, ll s, vector<ll> rVis)
    {
        if(c==s)
            return ans;
        if(dp.count({{vis,rVis},c}))
            return dp[{{vis,rVis},c}];
        ll op = 0;
        for(ll k=0; k<vect[0].size();k++)
        {
            if(vis[k]==0)
            {
                ll val = 0;
                vis[k] = 1;
                vector<ll> temp = rVis;
                for(ll i=0;i<vect.size();i++)
                {
                    ll count = 0;
                    ll ok = 1;
                    for(ll j=0;j<vect[0].size();j++)
                    {
                        if(vect[i][j]==1)
                        {
                            count++;
                            if(vis[j]==0)
                                ok = 0;
                        }
                    }
                    if((ok==1 or count==0) and temp[i]==0)
                        temp[i] = 1, val++;
                }
                op = max(maxRow(vect,ans+val,vis,c+1,s,temp),op);
                vis[k] = 0;
            }
        }
        return dp[{{vis,rVis},c}] = op;
    }
    
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector<ll> vis(matrix[0].size(),0);
        vector<ll> rVis(matrix.size(),0);
        return maxRow(matrix,0,vis,0,numSelect,rVis);
    }
};