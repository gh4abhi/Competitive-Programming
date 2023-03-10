// Problem Link - https://leetcode.com/contest/weekly-contest-308/problems/minimum-amount-of-time-to-collect-garbage/

#define ll int

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        ll ans = 0;
        vector<map<char,ll>> vect(garbage.size());
        for(ll i=0;i<garbage.size();i++)
            for(auto j:garbage[i])
                vect[i][j]++;
        for(ll i=1;i<travel.size();i++)
            travel[i] += travel[i-1];
        vector<char> op = {'G','P','M'};
        ll dis = 0;
        for(ll i=0;i<garbage.size();i++)
            for(auto j:op)
                if(vect[i][j])
                    ans += vect[i][j];
        for(auto j:op)
        {
            for(ll i=garbage.size()-1;i>0;i--)
            {
                if(vect[i][j])
                {
                    ans += travel[i-1];
                    break;
                }
            }
        }
        return ans;
    }
};