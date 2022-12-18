// Problem Link - https://leetcode.com/contest/weekly-contest-324/problems/smallest-value-after-replacing-with-sum-of-prime-factors/

#define ll int

class Solution {
public:
    
    ll num(ll n)
    {
        ll ans = 0;
        ll ok = 0;
        while(n%2==0)
        {
            n/=2;
            ans+=2;
        }
        for(ll i=3;i<=sqrt(n);i+=2)
        {
            ll op = 0;
            while(n%i==0)
            {
                op = 1;
                n/=i;
                ans+=i;
            }
        }
        if(n>2)
            ans += n;
        return ans;
    }
    
    int smallestValue(int n) {
        ll mini = n;
        ll ok = n;
        ll ans = INT_MAX;
        while(ok<=ans)
        {
            ok = num(ok);
            if(ok==ans)
                break;
            ans = min(ok,ans);
        }
        return ans;
    }
};