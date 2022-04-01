// Problem Link - https://leetcode.com/contest/weekly-contest-286/problems/minimum-deletions-to-make-array-beautiful/

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        ll del = 0;
        ll n = nums.size();

        for(ll i=0;i<n-1;i++)
       {
           if((i-del)%2==0 and nums[i]==nums[i+1])
           {
               del++;
           }
       }
        if((n-del)&1)
            del++;
        return del;
    }
};