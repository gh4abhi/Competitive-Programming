// Problem Link - https://leetcode.com/contest/biweekly-contest-75/problems/find-triangular-sum-of-an-array/

#define ll int

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> temp = nums;
            while(temp.size()>1)
            {
                vector<ll> cur;
                for(ll i=1;i<temp.size();i++)
                {
                    ll val = (temp[i-1] + temp[i])%10;
                    cur.push_back(val);
                }
                temp = cur;
            }
        return temp[0];
    }
};