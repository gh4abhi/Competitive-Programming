// Problem Link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/


#define ll int

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<ll> ans;
        vector<pair<ll,ll>> v;
        ll ind = 0;
        for(auto i:mat)
        {
            ll count = 0;
            for(auto j:i)
            {
                if(j==0)
                    break;
                count++;
            }
            v.push_back({count,ind});
                ind++;
        }
        sort(v.begin(),v.end());
        for(ll i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};