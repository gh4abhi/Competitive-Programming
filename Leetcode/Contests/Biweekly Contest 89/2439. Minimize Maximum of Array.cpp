// Problem Link - https://leetcode.com/contest/biweekly-contest-89/problems/minimize-maximum-of-array/

#define ll long long

class Solution {
public:
    
    bool isPossible(vector<ll> vect, ll x)
    {
        for(ll i=vect.size()-1;i>=1;i--)
        {
            if(vect[i]>x)
            {
                ll op = vect[i]-x;
                vect[i] = x;
                vect[i-1] += (ll)op;
            }
        }
        return vect[0]<=x;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        ll start = 0, end = *max_element(nums.begin(),nums.end());
        ll ans;
        vector<ll> op(nums.size());
        for(ll i=0;i<nums.size();i++)
            op[i] = (ll)nums[i];
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(isPossible(op,mid))
               ans = mid, end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
};

// [6,9,3,8,14] -> 8
// [4,7,2,2,9,19,16,0,3,15] -> 9