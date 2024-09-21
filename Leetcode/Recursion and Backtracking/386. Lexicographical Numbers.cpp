// Problem Link - https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21

#define ll int

class Solution {
public:

    void fun(ll sum, ll ind, vector<ll> & ans, ll n)
    {
        if(sum>n or ind>9)
            return;
        ans.push_back(sum);
        fun(sum*10,0,ans,n);
        if((sum+1)%10!=0)
            fun(sum+1,ind+1,ans,n);
    }

    vector<int> lexicalOrder(int n) {
        vector<ll> ans;
        fun(1,0,ans,n);
        return ans;
    }
};