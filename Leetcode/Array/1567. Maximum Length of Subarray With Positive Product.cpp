// Problem Link - https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

#define ll long long

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        ll ans = 0;
        ll pro = 1;
        ll n = nums.size();
        ll op = -1;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                nums[i] = 1;
            else if(nums[i]<0)
                nums[i] = -1;
        }
        for(ll i=0;i<n;i++)
        {
            if(nums[i]==0)
                op = i,pro=1;
            else
            {
                pro*=nums[i];
                if(pro>0)
                    ans = max(ans,i-op);
            }
        }
        op = n;
        pro = 1;
        for(ll i=n-1;i>=0;i--)
        {
            if(nums[i]==0)
                op = i,pro=1;
            else
            {
                pro*=nums[i];
                if(pro>0)
                    ans = max(ans,(n-i)-(n-op));
            }
        }
        return ans;
    }
};