// Problem Link - https://www.codingninjas.com/codestudio/problems/799354?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<ll> ans(n,-1);
    stack<ll> st;
    for(ll i=n-1;i>=0;i--)
    {
        if(st.size()==0)
        {
            ans[i] = -1;
            st.push(arr[i]);
            continue;
        }
        while(st.size() and arr[i]>=st.top())
            st.pop();
        if(st.size())
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(arr[i]);
    }
    return ans;
}