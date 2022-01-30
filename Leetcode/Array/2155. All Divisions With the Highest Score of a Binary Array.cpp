// Problem Link - https://leetcode.com/contest/weekly-contest-278/problems/all-divisions-with-the-highest-score-of-a-binary-array/

#define ll int

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> left(n), right(n);
        ll c = 0;
        for(ll i=0;i<n;i++)
        {
            if(nums[i]==0)
                c++;
            left[i] = c;
        }
        c = 0;
        for(ll i=n-1;i>=0;i--)
        {
            if(nums[i]==1)
                c++;
            right[i] = c;
        }
        ll maxi = INT_MIN;
        for(ll i=0;i<=n;i++)
        {
            if(i==0)
            {
                maxi = max(right[0],maxi);
                continue;
            }
            if(i==n)
            {
                maxi = max(maxi,left[n-1]);
                break;
            }
            maxi = max(left[i-1]+right[i],maxi);
        }
        
        vector<ll> ans;
        
        for(ll i=0;i<=n;i++)
        {
            if(i==0)
            {
                if(right[0]==maxi)
                    ans.push_back(i);
                continue;
            }
            if(i==n)
            {
                if(maxi==left[n-1])
                    ans.push_back(i);
                break;
            }
            
            if(left[i-1]+right[i]==maxi)
                ans.push_back(i);
        }
        return ans;
    }
};
