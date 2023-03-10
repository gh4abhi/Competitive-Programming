// Problem Link - https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll long long

class minStack
{
    ll mini;
 stack<ll> st;   
public:
    minStack() {
        while(st.size())
            st.pop();
        mini = 1e18;
    }
    
    void push(int val) {
        if(st.size()==0)
            st.push(val), mini = val;
        else
        {
            if(val<mini)
                st.push(2ll*val-mini), mini = val;
            else
                st.push(val);
        }
    }
        int pop()
        {
            if(st.size()==0)
            return -1;
        if(st.top()<mini)
        {
            ll val = mini;
            mini = 2ll*mini - st.top();
            st.pop();
            return val; 
        }
        else
        {
            ll val = st.top();
            st.pop();
            return val;
        }
        }
        
        int top()
        {
            if(st.size()==0)
                return -1;
        if(st.top()<mini)
            return mini;
        else
            return st.top();
        }
        
        int getMin()
        {
            if(st.size()==0)
                return -1;
            return mini;
        }
};