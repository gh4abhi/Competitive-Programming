// Problem Link - https://leetcode.com/contest/weekly-contest-291/problems/minimum-consecutive-cards-to-pick-up/

#define ll int

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<ll,ll> m;
        ll ans = INT_MAX;
        for(ll i=0;i<cards.size();i++)
        {
            if(m.count(cards[i])==0)
            {
                m[cards[i]] = i;
                continue;
            }
            ll val = i - m[cards[i]] +1;
            ans = min(ans,val);
            m[cards[i]] = i;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};