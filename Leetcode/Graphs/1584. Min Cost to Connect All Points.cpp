// Problem Link - https://leetcode.com/problems/min-cost-to-connect-all-points/

#define ll int

class Solution {
public:
  
  
    ll findPar(ll u, vector<ll>& par)
    {
        if(par[u]==u)
            return u;
        return par[u] = findPar(par[u],par);
    }
    
   
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<ll,pair<ll,ll>>> Edge;
        map<ll,pair<ll,ll>> v;
        ll j=0;
        ll n = points.size();
        for(auto i:points)
        {
            v[j] =  make_pair(i[0],i[1]);
            j++;
        }
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=i+1;j<n;j++)
            {
                ll dis = abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second);
                Edge.push_back(make_pair(dis,make_pair(i,j)));
            }
        }
        
        sort(Edge.begin(), Edge.end());
        
       /* for(auto i:Edge)
        {
            cout<<i.second.first<<" "<<i.second.second<<" "<<i.first<<endl;
        }*/
         vector<ll> par(n);
        for(ll i=0;i<n;i++)
        {
            par[i] = i;
        }
          
        ll count = 0, i=0,sum=0;
        
        for(auto i:Edge)
        {
            ll w = i.first;
            ll v1 = i.second.first;
            ll v2 = i.second.second;   
            ll a = findPar(v1,par);
            ll b = findPar(v2,par);
            if(a!=b)
            {
                sum+=w;
                
                par[b] = par[a];
                count++;
            }
            if(count==n-1)
                break;
        }
        
        return sum;
        
    }
};
