// Problem Link - https://leetcode.com/problems/reverse-string-ii/

#define ll int

class Solution {
public:
    ll min(ll a, ll b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    string reverseStr(string s, int k) {
        for(ll i=0;i<s.length();i+=2*k)
        {
            ll start = i, j = min(start + k-1,s.length()-1);
            while(start<j)
            {
                swap(s[start],s[j]);
                start++;
                j--;
            }
        }
        return s;
    }
};