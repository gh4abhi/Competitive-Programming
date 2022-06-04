// Problem Link - https://leetcode.com/problems/majority-element-ii/

#define ll int

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ll count1 = 0, count2 = 0;
        ll num1 = -1, num2 = -1;
        for(ll i=0;i<nums.size();i++)
        {
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
            else if(count1==0)
                num1 = nums[i],count1++;
            else if(count2==0)
                num2 = nums[i], count2++;
            else
                count1--,count2--;
        }
        count1 = 0, count2 = 0;
        for(auto i:nums)
        {
            if(i==num1)
                count1+=1;
            if(i==num2)
                count2+=1;
        }
        vector<ll> ans;
        if(count1>nums.size()/3)
            ans.push_back(num1);
        if(count2>nums.size()/3 and num1!=num2)
            ans.push_back(num2);
        return ans;
    }
};