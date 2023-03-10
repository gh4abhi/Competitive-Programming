// Problem Link - https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

#define ll int

class Solution {
public:
    
    ll ans = 0;
    
    bool isPalindrome(string &str)
    {
        ll start = 0, end = str.length()-1;
        while(start<=end)
            if(str[start++]!=str[end--])
                return false;
        return true;
    }
    
    ll maxi(ll ind, string &s, string &a, string &b)
    {
        if(ind==s.length())
        {
            ll ok = 1;
            if(!isPalindrome(a))
                ok = 0;
            if(!isPalindrome(b))
                ok = 0;
            if(ok)
                return a.length()*1LL*b.length();
            return INT_MIN;
        }
        string str1 = a + s[ind];
        string str2 = b + s[ind];
        return max({maxi(ind+1,s,str1,b),maxi(ind+1,s,a,str2),maxi(ind+1,s,a,b)});
    }
    
    int maxProduct(string s) {
        string a = "";
        string b = "";
        return maxi(0,s,a,b);
    }
};