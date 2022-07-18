// Problem Link - https://www.codingninjas.com/codestudio/problems/1058184?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
int largestRectangle(vector < int > & heights) {
    stack<ll> st;
    ll ans = 0;
    ll n = heights.size();
    for(ll i=0;i<=n;i++)
    {
        while(st.size() and (i==n or heights[i]<= heights[st.top()]))
        {
            ll val = heights[st.top()];
            st.pop();
            ll width;
            if(st.size()==0)
                width = i;
            else 
                width = i-(st.top()) -1;
            ans = max(ans,width*val);
        }
        st.push(i);
    }
    return ans;
}