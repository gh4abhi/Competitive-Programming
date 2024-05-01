// Problem Link - https://leetcode.com/problems/find-the-integer-added-to-array-ii/

#define ll int

class Solution {
public:
    unordered_map<ll,unordered_map<ll,unordered_map<ll,unordered_map<ll,ll>>>> dp;
    ll mini(ll i, ll j, ll flag, ll val, vector<ll> &nums1, vector<ll> &nums2)
    {
        if(j==nums2.size())
            return val;
        if(dp.count(i) and dp[i].count(j) and dp[i][j].count(val) and dp[i][j][val].count(flag))
            return dp[i][j][val][flag];
        ll ans = 1e6;
        if(nums2[j]-nums1[i]==val or val==1002)
        {
            ans = mini(i+1,j+1,flag,nums2[j]-nums1[i],nums1,nums2);
            if(flag>0)
                ans = min(ans,mini(i+1,j,flag-1,val,nums1,nums2));
        }
        else
        {
            if(flag>0)
                ans = min(ans,mini(i+1,j,flag-1,val,nums1,nums2));
        }
        return dp[i][j][val][flag] = ans;
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return mini(0,0,2,1002,nums1,nums2);
    }
};