// Problem Link - https://leetcode.com/contest/biweekly-contest-77/problems/minimum-average-difference/

#define ll long long

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        map<ll,ll> m;
        vector<ll> pre, pos;
        ll sum = 0;
        for(ll i= i=0;i<nums.size();i++)
        {
            sum += nums[i];
            pre.push_back(sum);
        }
        sum = 0;
        for(ll i=nums.size()-1;i>=0;i--)
        {
         pos.push_back(sum);
            sum += nums[i];
        }
        reverse(pos.begin(),pos.end());
        ll s = 1, e = nums.size()-1;
        ll ans = 0, mini = INT_MAX;
        for(ll i=0;i<nums.size();i++)
        {
            ll val1 = pre[i];
            ll val2 = pos[i];
            val1/=s;
            if(e==0)
                e=1;
            val2/=e;
            ll ok = abs(val1-val2);
            if(ok<=mini)
            {
                if(mini==ok)
                ans = min(i,ans);
                else
                    ans = i;
                mini = ok;
            }
            s++;
            e--;
        }
        return ans;
    }
};