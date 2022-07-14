// Problem Link - https://www.interviewbit.com/problems/nearest-smaller-element/

#define ll int
vector<int> Solution::prevSmaller(vector<int> &arr) {
    ll n = arr.size();
    stack<ll> st;
    vector<ll> ans(n,-1);
    for(ll i=0;i<n;i++)
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
