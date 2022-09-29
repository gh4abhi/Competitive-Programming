// Problem Link - https://leetcode.com/problems/first-missing-positive/

#define ll long long

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        ll n = arr.size();
        for(ll i=0;i<arr.size();i++)
        {
            ll op = arr[i]-1ll;
            while(arr[i]>0 and arr[i]<n+1 and arr[i]!=arr[op])
            {
                swap(arr[i],arr[op]);
                op = arr[i] -1;
            }
        }
        for(ll i=0;i<arr.size();i++)
             if(arr[i]-1ll!=i)
                 return i+1;
        return arr.size()+1;
    }
};