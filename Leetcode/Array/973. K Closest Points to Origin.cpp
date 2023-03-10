// Problem Link - https://leetcode.com/problems/k-closest-points-to-origin/

#define ll int

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<ll,pair<ll,ll>>> vect(points.size());
        for(ll i=0; i<points.size();i++)
        {
            ll x = points[i][0];
            ll y = points[i][1];
            ll dis = x*x + y*y;
            vect[i] = (make_pair(dis,make_pair(x,y)));
        }
        
        sort(vect.begin(),vect.end());
        vector<vector<ll>> ans(k);
        for(ll i=0;i<k;i++)
        {
            ans[i].push_back(vect[i].second.first);
            ans[i].push_back(vect[i].second.second);
        }
        return ans;
    }
};
