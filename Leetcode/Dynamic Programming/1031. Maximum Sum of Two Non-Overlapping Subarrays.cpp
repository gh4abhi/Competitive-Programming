// Problem Link - https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

#define ll int
class Solution {
public:
    ll ans = 0;
    void maxSum(vector<int>& nums, int firstLen, int secondLen)
    {
        ll n = nums.size();
        ll dp1[n];
        memset(dp1,0,sizeof(dp1));
        ll sum = 0;
        for(ll i=0;i<n;i++)
        {
            if(i<firstLen)
                sum+=nums[i],dp1[i] = sum;
            else
            {
                sum += nums[i] - nums[i-firstLen];
                dp1[i] = max(sum,dp1[i-1]);
            }
        }
        sum = 0;
        ll dp2[n];
        memset(dp2,0,sizeof(dp2));
        for(ll i=n-1;i>=0;i--)
        {
            if(n-i<=secondLen)
                sum += nums[i],dp2[i] = sum;
            else
            {
                sum += nums[i] - nums[i+secondLen];
                dp2[i] = max(sum,dp2[i+1]);
            }
        }
        for(ll i=0;i<n-secondLen;i++)
            ans = max(dp1[i]+dp2[i+1],ans);
        
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        maxSum(nums,firstLen,secondLen);
        maxSum(nums,secondLen,firstLen);
        return ans;
    }
};