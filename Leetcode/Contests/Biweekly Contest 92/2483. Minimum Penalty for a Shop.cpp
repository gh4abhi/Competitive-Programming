// Problem Link - https://leetcode.com/contest/biweekly-contest-92/problems/minimum-penalty-for-a-shop/

#define ll int

class Solution {
public:
    int bestClosingTime(string customers) {
        ll n = customers.length();
        vector<ll> pre(n+1,0);
        vector<ll> pos(n+1,0);
        ll op = 0;
        for(ll i=0;i<n;i++)
        {
            if(customers[i]=='N')
                op++;
            pre[i] = op;
        }
        op = 0;
        for(ll i=n-1;i>=0;i--)
        {
            if(customers[i]=='Y')
                op++;
            pos[i] = op;
        }
        pre[n] = pre[n-1];
        ll ans = -1;
        ll mini = INT_MAX;
        for(ll i=0;i<=n;i++)
        {
            ll ok = pre[i] + pos[i];
            if(i<n and customers[i]=='N')
                ok--;
            if(mini>ok)
                mini = ok, ans = i;
        }
        if(ans==n-1 and customers[ans]=='Y')
            ans++;
        return ans;
    }
};