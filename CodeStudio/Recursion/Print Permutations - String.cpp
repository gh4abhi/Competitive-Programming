// Problem Link - https://www.codingninjas.com/codestudio/problems/758958?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

void DFS(ll ind, vector<string> &ans, string &s)
{
    if(ind==s.length())
    {
        ans.push_back(s);
        return;
    }
    for(ll i=ind;i<s.length();i++)
    {
        swap(s[ind],s[i]);
        DFS(ind+1,ans,s);
        swap(s[ind],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    DFS(0,ans,s);
    return ans;
}