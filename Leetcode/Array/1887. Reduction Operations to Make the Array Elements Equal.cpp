// Problem Link - https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

#define ll int
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<ll,ll> m;
        ll mini = INT_MAX;
        for(auto i:nums)
            mini = min(i,mini);
        for(auto i:nums)
            if(i!=mini)
                m[-i]++;
        ll sum = 0;
        ll c = 0;
        for(auto i:m)
            sum += i.second+c,c+=i.second;
        return sum;
    }
};