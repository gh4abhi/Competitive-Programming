// Problem Link - https://leetcode.com/problems/contiguous-array/

#define ll int

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<ll,ll> m;
        ll sum = 0;
        m[0] = -1;
        ll ans = 0;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum+=-1;
            else 
                sum+=1;
            if(m.count(sum)>0)
                ans = max(ans,i - m[sum]);
            else
                m[sum] = i;
        }
        return ans;
    }
};
