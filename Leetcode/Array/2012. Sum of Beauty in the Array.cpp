// Problem Link - https://leetcode.com/problems/sum-of-beauty-in-the-array/

#define ll int

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<ll> pre(nums.size(),0);
        vector<ll> pos(nums.size(),0);
        ll mini = INT_MIN;
        ll ind1 = -1, ind2 = -1;
        for(ll i = 0;i<nums.size();i++)
        {
            pre[i] = mini;
            if(nums[i]>mini)
            {
                ind1 = i;
                mini = nums[i];
            }
        }
ll maxi = INT_MAX;
        for(ll i = nums.size()-1;i>=0;i--)
        {
            pos[i] = maxi;
            if(nums[i]<maxi)
            {
                ind2 = i;
                maxi = nums[i];
            }
        }
        ll ans = 0;
        for(ll i=1;i<nums.size()-1;i++)
        {
            //cout<<pre[i]<<" "<<nums[i]<<" "<<pos[i]<<endl;
            if(pre[i]<nums[i] and pos[i]>nums[i])
            {
                if(i-1==ind1 or i+1==ind2)
                    ans+=1;
                else 
                    ans +=2;
            }
            else if(nums[i]>nums[i-1] and nums[i]<nums[i+1])
                ans+=1;
        }
        return ans;
    }
};