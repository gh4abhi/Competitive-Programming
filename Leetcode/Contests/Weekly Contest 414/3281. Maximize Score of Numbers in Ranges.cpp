// Problem Link - https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/

#define ll long long

class Solution {
public:
    
    bool isPossible(vector<int> &vect, ll x, ll d)
    {
        ll pre = vect[0];
        for(ll j=1;j<vect.size();j++)
        {
            ll op = pre + x;
            if(op>vect[j]+d)
                return false;
            if(op<vect[j])
                pre = vect[j];
            else
                pre = op;
        }
        return true;
    }
    
    int maxPossibleScore(vector<int>& vect, int d) {
        sort(vect.begin(),vect.end());
        ll start = 0, end = 1e18;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(isPossible(vect,mid,d))
                start=mid+1;
            else
                end=mid-1;
        }
        return end;
    }
};