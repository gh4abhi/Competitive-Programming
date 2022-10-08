// Problem Link - https://www.interviewbit.com/problems/distinct-numbers-in-window/

#define ll int

vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B>A.size())
        return {};
    unordered_map<ll,ll> m;
    vector<ll> ans;
    for(ll i=0;i<A.size();i++)
    {
        if(i<B-1)
            m[A[i]]++;
        else
        {
            m[A[i]]++;
            ans.push_back(m.size());
            m[A[i-B+1]]--;
            if(m[A[i-B+1]]==0)
                m.erase(A[i-B+1]);
        }
    }
    return ans;
}
