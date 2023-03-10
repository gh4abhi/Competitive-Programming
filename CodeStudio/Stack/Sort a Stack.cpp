// Proble Link - https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

void sortStack(stack<int> &st)
{
    if(st.size()==0)
        return;
    ll cur = st.top();
    st.pop();
    sortStack(st);
    stack<ll> temp;
    while(st.size() and cur<st.top())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(cur);
    while(temp.size())
    {
        st.push(temp.top());
        temp.pop();
    }
}