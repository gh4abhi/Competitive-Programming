// Problem Link - https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<stack>
#define ll int

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<ll> st;
    vector<ll> ans(n,-1);
    for(ll i=n-1;i>=0;i--)
    {
        if(st.size()==0)
        {
            st.push(arr[i]);
            ans[i] = -1;
            continue;
        }
        while(st.size() and st.top()>=arr[i])
            st.pop();
        if(st.size())
            ans[i] = st.top();
        else
            ans[i] = -1;
        st.push(arr[i]);
    }
    return ans;
}