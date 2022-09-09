// Problem Link - https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#define ll int

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](vector<ll>& a, vector<ll>&b){
            if(a[0]!=b[0])
                return a[0]>b[0];
            return a[1]<b[1];
        });
        ll ans = 0;
        ll maxi = properties[0][1];
        for(ll i=1;i<properties.size();i++)
        {
            if(properties[i][1]<maxi)
                ans++;
            maxi = max(maxi,properties[i][1]);
        }
        return ans;
    }
};