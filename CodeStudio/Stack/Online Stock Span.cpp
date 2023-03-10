// Problem Link - https://www.codingninjas.com/codestudio/problems/span-of-ninja-coin_1475049?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
vector<int> findSpans(vector<int> &price) {
    ll n = price.size();    
    stack<ll> st;
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(i);
                ans.push_back(1);
                continue;
            }
            while(st.size() and price[st.top()]<=price[i])
                st.pop();
            if(st.size())
                ans.push_back(i-st.top());
            else
                ans.push_back(i+1);
            st.push(i);
        }
        return ans;
}