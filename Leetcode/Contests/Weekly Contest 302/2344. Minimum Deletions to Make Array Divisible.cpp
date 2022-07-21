// Problem Link - https://leetcode.com/contest/weekly-contest-302/problems/minimum-deletions-to-make-array-divisible/

#include<bits/stdc++.h>
#define ll long long

class Solution {
public:
    int gcdOn(int a, int b)
    {
    return b == 0 ? a : gcd(b, a % b);   
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        ll val = numsDivide[0];
        for(ll i=1;i<numsDivide.size();i++)
        {
            val = gcdOn(val,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        ll ind = -1e9;
        for(ll i=0;i<nums.size();i++)
        {
            if(val%nums[i]==0)
            {
                ind = i-1;
                break;
            }
        }
        if(ind==-1e9)
            return -1;
        return ind+1;
    }
};