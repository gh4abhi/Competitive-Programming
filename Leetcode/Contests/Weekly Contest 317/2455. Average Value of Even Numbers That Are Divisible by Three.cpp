// Problem Link - https://leetcode.com/contest/weekly-contest-317/problems/average-value-of-even-numbers-that-are-divisible-by-three/

#define ll long long

class Solution {
public:
    int averageValue(vector<int>& nums) {
        ll sum = 0;
        ll count = 0;
        for(auto i:nums)
        {
            if(i%2==0 and i%3==0 and i!=0)
                sum+=i,count++;
        }
        if(count==0)
            return 0;
        return sum/count;
    }
};