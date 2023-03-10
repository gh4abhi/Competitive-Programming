// Problem Link - https://www.codingninjas.com/codestudio/problems/longest-palindromic-substring_758900?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll expand(ll start, ll end, string &s)
{
    while(start>=0 and end<s.length() and s[start]==s[end])
        start--, end++;
    return end-start-1;
}

string longestPalinSubstring(string str)
{
    ll start = 0, end = 0;
    ll len = INT_MIN;
    for(ll i=0;i<str.length();i++)
    {
        ll op = max(expand(i,i,str),expand(i,i+1,str));
        if(op>len)
            len = op, start = i-(len-1)/2, end = i + (len)/2;
    }
    return str.substr(start,end-start+1);
}