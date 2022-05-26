// Problem Link - https://leetcode.com/contest/weekly-contest-294/problems/maximum-bags-with-full-capacity-of-rocks/

#define ll long long

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        ll n = capacity.size();
        vector<ll> vect(capacity.size());
        for(ll i=0;i<n;i++)
            vect[i] = i;
        sort(vect.begin(),vect.end(),[&capacity, &rocks](ll a, ll b){
            return (capacity[a]-rocks[a])<(capacity[b]-rocks[b]);
        });
        ll count = 0;
        for(auto i:vect)
        {
            ll val = min(additionalRocks,capacity[i]-rocks[i]);
            if(val+rocks[i]==capacity[i])
                count++;
            additionalRocks -= val;
        }
        return (int)count;
    }
};