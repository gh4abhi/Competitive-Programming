// Problem Link - https://leetcode.com/problems/reduce-array-size-to-the-half/

#define ll int

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<ll,ll> m;
        for(auto i:arr)
            m[i]++;
        vector<ll> vect;
        for(auto i:m)
            vect.push_back(i.second);
        sort(vect.begin(),vect.end(),greater<ll>());
        ll sum = 0;
        ll i = 0;
        while(sum<arr.size()/2)
            sum += vect[i++];
        return i;
    }
};