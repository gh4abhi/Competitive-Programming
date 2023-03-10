// Problem Link - https://leetcode.com/problems/count-good-meals/description/

#define ll long long
#define MOD 1000000007

class Solution {
public:

    ll twoSumSorted(ll target, unordered_map<ll,ll> &m)
    {
        ll ans = 0;
        for(auto i:m)
            if(m.count(target-i.first))
                {
                    if(i.first==target-i.first)
                        ans = (ans + (i.second*(i.second-1)));
                    else
                        ans  = (ans + (i.second*m[target-i.first]));
                }
        return ans/2;
    }

    int countPairs(vector<int>& deliciousness) {
        ll ans = 0;
        unordered_map<ll,ll> m;
        for(auto i:deliciousness)
            m[i]++;
        ll pro = 1;
        while(pro>0 and pro<LONG_MAX/2+1)
            ans = (ans+twoSumSorted(pro,m))%MOD,pro = pro*2;
        return ans;
    }
};