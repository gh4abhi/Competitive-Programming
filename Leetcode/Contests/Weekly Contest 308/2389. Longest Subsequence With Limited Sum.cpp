// Problem Link - https://leetcode.com/contest/weekly-contest-308/problems/longest-subsequence-with-limited-sum/

#define ll int

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<ll> ans;
        sort(nums.begin(),nums.end());
        for(auto i:queries)
        {
            ll count = 0;
            ll sum = 0;
            ll flag = 1;
            for(auto j:nums)
            {
                sum += j;
                if(sum>i)
                {
                    ans.push_back(count);
                    flag = 0;
                    break;
                }
                count++;
            }
            if(flag)
                ans.push_back(count);
        }
        return ans;
    }
};