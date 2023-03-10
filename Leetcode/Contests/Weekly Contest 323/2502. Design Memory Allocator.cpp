// Problem Link - https://leetcode.com/contest/weekly-contest-323/problems/design-memory-allocator/

#define ll int

class Allocator {
public:
    vector<ll> vis;
    ll n;
    map<ll,vector<pair<ll,ll>>> m;
    Allocator(int n) {
        for(ll i=0;i<n;i++)
            vis.push_back(0);
        this->n = n;
    }
    
    int allocate(int size, int mID) {
        ll op = 0;
        for(ll i=0;i<n;i++)
        {
            if(vis[i]==0)
                op++;
            else
                op = 0;
            if(op==size)
            {
                for(ll k=i-size+1;k<=i;k++)
                    vis[k] = 1;
                m[mID].push_back({i-size+1,i});
                return i-size+1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        if(m.count(mID)==0)
            return 0;
        ll ans = 0;
        for(auto i:m[mID])
        {
            ll start = i.first;
            ll end = i.second;
            for(ll k=start;k<=end;k++)
                vis[k] = 0;
            ans += (end-start+1);
        }
        m.erase(mID);
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */