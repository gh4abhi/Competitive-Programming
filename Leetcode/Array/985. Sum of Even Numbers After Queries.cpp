// Problem Link - https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#define ll int

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ll sum = 0;
        for(auto i:nums)
            if(!(i&1))
                sum += i;
        vector<ll> ans;
        for(auto i:queries)
        {
            if(!(nums[i[1]]&1))
                sum -= nums[i[1]];
            nums[i[1]] += i[0];
            if(!(nums[i[1]]&1))
                sum += nums[i[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};