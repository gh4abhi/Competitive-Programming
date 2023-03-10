// Problem Link - https://leetcode.com/contest/weekly-contest-287/problems/maximum-candies-allocated-to-k-children/

#define ll long long

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll sum = 0;
        for(auto i:candies)
            sum+=i;
        ll low = 1, high = sum;
        ll ans = 0;
        while(low<=high)
        {
            ll mid = (low + high)/2;
            ll cur = 0;
            for(auto i:candies)
                cur += i/mid;
            if(cur>=k)
            {
                ans = max(ans,mid);
                low = mid +1;
            }
            else
                high = mid -1;
        }
        return (int)ans;
    }
};