// Problem Link - https://leetcode.com/contest/biweekly-contest-83/problems/number-of-zero-filled-subarrays/

#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr) {
     vector<ll> vect;
        ll count = 0;
        for(auto i:arr)
        {
            if(i==0)
                count++;
            else
            {
                if(count!=0)
                    vect.push_back(count);
                count =0;
            }
        }
        if(count!=0)
            vect.push_back(count);
        ll ans = 0;
        for(auto i:vect)
        {
            ans += i;
            ll val = i;
            ans += max(0ll,((val-1)*(val))/2);
        }
        return ans;
    }
};