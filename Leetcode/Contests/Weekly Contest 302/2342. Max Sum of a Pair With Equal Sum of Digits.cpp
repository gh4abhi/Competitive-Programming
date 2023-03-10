// Problem Link - https://leetcode.com/contest/weekly-contest-302/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#define ll long long

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<ll,priority_queue<ll>> m;
        for(auto i:nums)
        {
            ll sum = 0;
            ll val = i;
            while(val)
            {
                sum += val%10;
                val/=10;
            }
        m[sum].push(i);
        }
        ll ans = -1;
        for(auto i:m)
        {
            if(i.second.size()>1)
            {
                ll a = i.second.top();
                i.second.pop();
                ll b = i.second.top();
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
};