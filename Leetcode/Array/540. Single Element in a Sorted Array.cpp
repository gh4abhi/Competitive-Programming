// Problem Link - https://leetcode.com/problems/single-element-in-a-sorted-array/

#define ll int

class Solution {
public:
    int singleNonDuplicate(vector<int>& vect) {
        ll a = vect[0];
        if(vect.size()==1)
        {
            return a;
        }
        ll b = a;
        for(ll i = 1; i<vect.size();i++)
        {
            a = a^(vect[i]);
            if(a!=0 and a!=vect[i])
            {
                return b;
            }
            b = a;
        }
        return a;
    }
};
