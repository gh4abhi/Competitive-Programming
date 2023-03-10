// Problem Link - https://leetcode.com/contest/biweekly-contest-84/problems/minimum-replacements-to-sort-the-array/

#define ll long long

class Solution {
public:
    long long minimumReplacement(vector<int> nums) {
        ll pre = nums[nums.size()-1];
        ll ans = 0;
        for(ll i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>pre)
            {
                if(nums[i]%pre==0)
                {
                    ans += nums[i]/pre - 1;
                }
                else
                {
                    ans += nums[i]/pre;
                    ll nT = nums[i]/pre+1;
                    pre = (nums[i]/nT);
                }
            }
            else
                pre = nums[i];
        }
        return  ans;
    }
};
// [2,10,20,19,1] -> 47
// [19,7,2,24,11,16,1,11,23] -> 73
// [12,9,7,6,17,19,21] -> 6