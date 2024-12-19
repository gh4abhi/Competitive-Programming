// Problem Link - https://leetcode.com/problems/max-chunks-to-make-sorted/?envType=daily-question&envId=2024-12-19

#define ll int

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<ll,ll>> vect;
        for(ll i=0;i<arr.size();i++)
            vect.push_back({min(arr[i],i),max(arr[i],i)});
        sort(vect.begin(),vect.end());
        stack<pair<ll,ll>> st;
        for(ll i=0;i<vect.size();i++)
        {
            if(st.size())
            {
                auto it = st.top();
                st.pop();
                if(vect[i].first<it.second)
                    st.push({it.first, max(it.second,vect[i].second)});
                else
                    st.push(it), st.push(vect[i]);
            }
            else
                st.push(vect[i]);
        }
        return st.size();
    }
};