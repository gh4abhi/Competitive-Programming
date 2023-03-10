// Problem Link - https://leetcode.com/problems/max-number-of-k-sum-pairs/

#define ll int
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<ll,ll> m;
        for(auto i:nums)
            m[i]++;
        ll ans=0;
        for(auto i:nums)
        {if(m[i] and m[k-i] and i!=k-i)
                m[i]--,m[k-i]--,ans++;
          if(i ==k-i and m[i]-2>=0)
                m[i]-=2,ans++;}
               
        return ans;
    }
};