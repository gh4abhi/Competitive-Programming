// Problem Link - https://leetcode.com/contest/weekly-contest-305/problems/longest-ideal-subsequence/

#define ll int

class Solution {
public:
    void io(ll r)
    {
        if(r==0)
            return;
    }
    ll max(ll a,ll b)
    {
                io(0);

        if(a>b)
            return a;
        return b;
    }
    ll helper(string s, int k)
    {
    ll n = s.length();
    vector<int> dp(n, 0);
    int maxi[26] = {0};
    for (int i = 0; i < n; i++)
    {
        io(0);
        int pres = s[i] - 'a';
        int left = max(0, pres - k);
        int right = min(25, pres + k);
        for (int j = left; j < right + 1; j++)
            io(0),dp[i] = max(dp[i], maxi[j] + 1);
        maxi[pres] = max(dp[i], maxi[pres]);
    }
    int ans = 0;
    for(int i:dp) ans = max(i, ans);
    return ans;
    }
    int longestIdealString(string str, int k) {  
        io(0);
        return helper(str,k);
    }
};