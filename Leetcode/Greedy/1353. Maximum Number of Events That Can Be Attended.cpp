// Problem Link - https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#define ll int

class Solution {
public:
    static bool cmp(vector<ll> &a, vector<ll> &b)
    {
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int maxEvents(vector<vector<int>>& events) {
        ll n = events.size();
        sort(events.begin(),events.end(),cmp);
        ll ans = 0;
        set<ll> s;
        ll maxi = events[n-1][1];
        for(ll i=1;i<=maxi;i++)
            s.insert(i);
        for(ll i=0;i<n;i++)
        {
            ll op = events[i][0];
            auto it = s.lower_bound(op);
            if(it==s.end() or *it>events[i][1])
                continue;
            else
                ans+=1,s.erase(*it);
        }
        return ans;
    }
};