// Problem Link - https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#define ll int

class Solution {
public:
    
    ll maxLen(vector<string> &arr, ll ind, vector<ll> &fre)
    {
        if(ind==arr.size())
            return 0;
        ll flag = 1;
        for(auto i:arr[ind])
        {
            fre[i-'a']+=1;
            if(fre[i-'a']>1)
                flag = 0;
        }
        ll ans = 0;
        if(flag)
            ans = max(ans,(ll)arr[ind].length() + maxLen(arr,ind+1,fre));
        for(auto i: arr[ind])
            fre[i-'a']-=1;
        return ans = max(ans,maxLen(arr,ind+1,fre));
    }
    
    int maxLength(vector<string>& arr) {
        vector<ll> fre(26,0);
        return maxLen(arr,0,fre);
    }
};