// Problem Link - https://www.codingninjas.com/codestudio/problems/799931?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

bool isPalindrome(string &s, ll start, ll end)
{
    while(start<=end)
        if(s[start++]!=s[end--])
            return false;
    return true;
}

void DFS(ll ind, vector<vector<string>> &ans, vector<string> &ds, string &s)
{
    if(ind==s.length())
    {
        ans.push_back(ds);
        return;
    }
    for(ll i=ind;i<s.length();i++)
    {
        if(isPalindrome(s,ind,i))
        {
            ds.push_back(s.substr(ind,i-ind+1));
            DFS(i+1,ans,ds,s);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> ds;
    DFS(0,ans,ds,s);
    return ans;
}