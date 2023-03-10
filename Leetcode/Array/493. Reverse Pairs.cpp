// Problem Link - https://leetcode.com/problems/reverse-pairs/

#define ll int

class Solution {
public:
    
    ll merge(vector<ll> &nums, vector<ll> &temp, ll start, ll mid, ll end)
    {
        ll i = start, j = mid+1;
        ll ans = 0;
        while(i<=mid)
        {
            while(j<=end and nums[i]>(long)2*nums[j])
                j++;
            ans += (j-(mid+1));
            i+=1;
        }
        i = start;
        j = mid+1;
        ll k = start;
        while(i<=mid and j<=end)
        {
            if(nums[i]<nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i<=mid)
            temp[k++] = nums[i++];
        while(j<=end)
            temp[k++] = nums[j++];
        for(ll ind = start; ind<=end; ind++)
            nums[ind] = temp[ind];
        return ans;
    }
    
    ll mergeSort(vector<ll>& nums, vector<ll> &temp, ll start, ll end)
    {
        if(start<end)
        {
            ll mid = start + (end-start)/2;
            ll ans = 0;
            ans += mergeSort(nums,temp,start,mid);
            ans += mergeSort(nums,temp,mid+1,end);
            ans += merge(nums,temp,start,mid,end);
            return ans;
        }
        return 0;
    }
    
    int reversePairs(vector<int>& nums) {
        vector<ll> temp(nums.size());
        return mergeSort(nums,temp,0,nums.size()-1);
    }
};