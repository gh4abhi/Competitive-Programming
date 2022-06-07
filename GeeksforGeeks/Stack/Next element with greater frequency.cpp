// Problem Link - https://practice.geeksforgeeks.org/problems/9656e96f6eaee49e67400fa2aed7833c8d9846b8/1#

#define ll int
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        stack<ll> st;
        vector<ll> ans(n,-1);
        map<ll,ll> m;
        for(ll i=0;i<n;i++)
            m[arr[i]]++;
        for(ll i=0;i<n;i++)
        {
            if(st.empty() or m[arr[i]]<m[arr[st.top()]])
                st.push(i);
            else
            {
                while(st.size() and m[arr[i]]>m[arr[st.top()]])
                    ans[st.top()] = arr[i], st.pop();
                st.push(i);
            }
        }
        return ans;
    }
};
