// Problem Link - https://leetcode.com/problems/frog-jump-ii/

#define ll int

class Solution {
public:
    
    bool isPossible(vector<ll> &stones, ll x)
    {
        ll n = stones.size();
        vector<ll> vis(n,0);
        ll op = stones[0]+x;
        for(ll i=1;i<stones.size();i++)
        {
            if(stones[i]>op and i-1==0)
                return false;
            else if(stones[i]>op)
                op = stones[i-1] + x, vis[i-1] = 1;
        }
        op = stones[n-1] - x;
        ll ok = -1;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=n-2;i>=0;i--)
        {
            if(vis[i]==1)
                continue;
            else if(stones[i]<op and pq.size()==0)
                return false;
            else if(stones[i]<op)
            {
                while(stones[i]<op and pq.size())
                {
                    op = pq.top()-x;
                    pq.pop();
                }
                if(op>stones[i])
                    return false;
                pq.push(stones[i]);
            }
            else
                pq.push(stones[i]), vis[i] = 1;
        }
        return true;
    }
    
    int maxJump(vector<int>& stones) {
        ll start = 0, end = 1e9+1;
        ll ans = 0;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(isPossible(stones,mid)==true)
              ans = mid,end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
};