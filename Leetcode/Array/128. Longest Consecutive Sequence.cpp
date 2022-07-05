// Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/

#define ll int
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<ll,bool> m;
        for(auto i:nums)
            m[i]=true;
        for(auto i:nums)
            if(m.count(i-1))
                m[i] = false;
        ll maxLen = 0;
        for(auto i:nums)
        {
            if(m[i])
            {
                ll curLen = 0;
                ll val = i;
                while(m.count(val))
                    val++,curLen++;
                maxLen = max(maxLen,curLen);
            }
        }
        return maxLen;
    }
};