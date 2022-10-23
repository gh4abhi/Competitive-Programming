// Problem Link - https://leetcode.com/problems/set-mismatch/

#define ll int

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        ll n = arr.size();
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]>0)
                arr[abs(arr[i])-1] *= (-1);
            else
                ans.push_back(abs(arr[i]));
        }
        for(ll i=0;i<n;i++)
            if(arr[i]>0)
                ans.push_back(i+1);
        return ans;
    }
};