// Problem Link - https://leetcode.com/problems/4sum/

#define ll long long

class Solution {
public:
    
    void twoSumSorted(vector<int> &nums, vector<vector<int>> &ans, ll a, ll b, ll target)
    {
        ll start = b+1, end = nums.size()-1;
        while(start<end)
        {
            ll sum = nums[start] + nums[end];
            if(sum>target)
                end -=1;
            else if(sum<target)
                start+=1;
            else
            {
                ans.push_back({nums[a],nums[b],nums[start],nums[end]});
                start+=1;
                end-=1;
                while(nums[start]==nums[start-1] and start<end)
                    start+=1;
                while(nums[end]==nums[end+1] and start<end)
                    end-=1;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
        for(ll i=0;i<nums.size()-3;i++)
            if(i==0 or nums[i]!=nums[i-1])
                for(ll j=i+1;j<nums.size()-2;j++)
                    if(j==i+1 or nums[j]!=nums[j-1])
                        twoSumSorted(nums,ans,i,j,(ll)target-(nums[i]+nums[j]));
        return ans;
    }
};