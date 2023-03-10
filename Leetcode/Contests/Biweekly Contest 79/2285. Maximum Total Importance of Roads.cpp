// Problem Link - https://leetcode.com/contest/biweekly-contest-79/problems/maximum-total-importance-of-roads/

#define ll long long

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll,ll> m;
        for(auto i:roads)
        {
            m[i[0]]++;
            m[i[1]]++;
        }
        vector<ll> vect(n,0);
        ll k = 0;
        for(auto i:m)
        {
            vect[k++] = i.second;
        }
        sort(vect.begin(),vect.end(),greater<ll>());
        ll ans = 0;
        ll val = n;
        for(ll i=0;i<n;i++)
        {
            ans += (val*vect[i]);
            val--;
        }
        return ans;
    }
};