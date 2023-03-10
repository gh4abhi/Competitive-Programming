// Problem Link - https://leetcode.com/problems/k-diff-pairs-in-an-array/

#define ll long long
class Solution {
public:
    int findPairs(vector<int>& vect, int k) {
     map<ll,ll> m1;
        ll sum = 0;
        map<ll,bool> m;
        for(auto i:vect)
        {
            m[i]=true;
            m1[i]++;
        }
        if(k!=0)
        {
        for(auto i:m)
        {
            if(m.count(i.first-k)>0 and (m[i.first] or m[i.first-k]))
            {
                sum++;
                m[i.first] = false;
                m[i.first-k] = false;
            }
            if(m.count(i.first+k)>0 and (m[i.first] or m[i.first+k]))
            {
                sum++;
                m[i.first] = false;
                m[i.first+k] = false;
            }
        }
        }
        else
        {
            for(auto i:m1)
            {
                if(i.second>=2)
                {
                    sum++;
                }
            }
        }
    return sum;
    }
};
