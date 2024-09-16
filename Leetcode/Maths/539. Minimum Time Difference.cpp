// Problem Link - https://leetcode.com/problems/minimum-time-difference/description/

#define ll int

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        ll ans = INT_MAX;
        ll n = timePoints.size();
        ll h1 = stoi(timePoints[n-1].substr(0,2));
        ll m1 = stoi(timePoints[n-1].substr(3,2));
        ll h2 = stoi(timePoints[0].substr(0,2));
        ll m2 = stoi(timePoints[0].substr(3,2));
        ll x = 0;
        if(m1!=0)
            h1+=1, x = 60;
        else
            x = 2*m1;
        ans = min(ans,(h2-h1+24)*60 + (x-m1)+m2);
        for(ll i=1;i<timePoints.size();i++)
        {
            ll h1 = stoi(timePoints[i-1].substr(0,2));
            ll m1 = stoi(timePoints[i-1].substr(3,2));
            ll h2 = stoi(timePoints[i].substr(0,2));
            ll m2 = stoi(timePoints[i].substr(3,2));
            ll x = 0;
            if(m1!=0)
                h1+=1, x = 60;
            else
                x = 2*m1;
            ans = min(ans,(h2-h1)*60 + (x-m1)+m2);
        }
        return ans;
    }
};