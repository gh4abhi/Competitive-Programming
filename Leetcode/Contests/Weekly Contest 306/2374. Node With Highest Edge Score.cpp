// Problem Link - https://leetcode.com/contest/weekly-contest-306/problems/node-with-highest-edge-score/

#define ll long long

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<ll,ll> m;
        ll maxi = -1e9;
        for(ll i=0;i<edges.size();i++)
        {
            m[edges[i]]+=i;
            maxi = max(maxi,m[edges[i]]);
        }
        vector<ll> vect;
        for(auto i:m)
        {
            if(i.second==maxi)
                vect.push_back(i.first);
        }
        sort(vect.begin(),vect.end());
        return (int)vect[0];
    }
};