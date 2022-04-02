// Problem Link - https://leetcode.com/contest/biweekly-contest-75/problems/number-of-ways-to-select-buildings/

#define ll long long
#define MOD 1000000007
class Solution {
public:
  
    long long numberOfWays(string s) {
        vector<ll> pre(s.length(),0);
        vector<ll> pos(s.length(),0);
        ll count = 0;
        for(ll i=0;i<s.length();i++)
        {
            pre[i] += count;
            if(s[i]=='0')
                count++;
        }
        count = 0;
        for(ll i = s.length()-1;i>=0;i--)
        {
            pos[i] += count;
            if(s[i]=='0')
                count++;
        }
        ll ans1 = 0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            ans1 += pre[i]*pos[i];
        }
        vector<ll> pre2(s.length(),0);
        vector<ll> pos2(s.length(),0);
        ll count2 = 0;
        for(ll i=0;i<s.length();i++)
        {
            pre2[i] += count2;
            if(s[i]=='1')
                count2++;
        }
        count2 = 0;
        for(ll i = s.length()-1;i>=0;i--)
        {
            pos2[i] += count2;
            if(s[i]=='1')
                count2++;
        }
        ll ans2 = 0;
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            ans2 += pre2[i]*pos2[i];
        }
        return ans1 + ans2;
    }
};