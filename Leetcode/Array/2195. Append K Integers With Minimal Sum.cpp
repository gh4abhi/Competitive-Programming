// Problem Link - https://leetcode.com/problems/append-k-integers-with-minimal-sum/

#define ll long long
class Solution {
public:
    ll mini(ll a, ll b)
    {
        if(a<b)
            return a;
        return b;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        ll sum = 0;
        sort(nums.begin(),nums.end());
        cout<<endl;
       if(nums[0]>1)
       {
           ll start = 1;
           ll end = mini(nums[0]-1,start + k-1);
               ll n=end - start +1;
               sum += ((start+end)*n)/2;
               k-=n;
          
       }
     
        for(ll i = 1;i<nums.size();i++)
        {
            ll start=nums[i-1] + 1;
            ll end = mini(nums[i] -1, start + k - 1);
            if(start>end)
                continue;

            k -= (end - start +1);
            ll n = end - start +1;
            sum += ((n)*(start + end))/2;
            if(k==0)
                return sum;
        }
        if(k)
        {
            ll start = nums[nums.size()-1] +1;
            ll end = start + k - 1;

            ll n = k;
            sum += ((n)*(start + end))/2;
        }
        return sum;
    }
};