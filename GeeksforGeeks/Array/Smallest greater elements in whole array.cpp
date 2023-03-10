// Problem Link - https://practice.geeksforgeeks.org/problems/smallest-greater-elements-in-whole-array2751/1

#define ll int
int* greaterElement(int arr[], int n)
{
    int *ans = new int[n];
    
    int neg = 1e7;
    neg *= -1;
    set<ll> st;
    for(ll i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    for(ll i=0;i<n;i++)
    {
        auto it = st.find(arr[i]);
        it++;
        if(it!=st.end())
        ans[i] = *it;
        else
        ans[i] = neg;
    }
    return ans;
}