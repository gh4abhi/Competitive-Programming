// Problem Link - https://leetcode.com/problems/search-a-2d-matrix/

#define ll int

class Solution {
public:
    ll findRow(vector<vector<ll>> vect, ll n, ll m, ll val)
{
    ll low = 0;
    ll high = n-1;
    
    while(low<=high)
    {
        ll mid = (low + high)/2;
        if(val>=vect[mid][0] and val<=vect[mid][m-1])
        {
            return mid;
        }
        else if(vect[mid][0]>val)
        {
            high = mid-1;
        }
        else if(vect[mid][0]<val)
        {
            low = mid+1;
        }
    }
    return -1;
}
    
    bool searchMatrix(vector<vector<int>>& vect, int val) {
        
        ll n = vect.size();
        ll m = vect[0].size();
        
        ll row = findRow(vect, n, m, val);
    

    
    ll flag = 1;
    
    if(row==-1)
    {
     return false;
     flag = 0;
    }
    
    ll low = 0;
    ll high = m-1;
    if(flag)
    while(low<=high)
    {
        ll mid = (low+high)/2;
        
        if(vect[row][mid]==val)
        {
            return true;
        }
        else if(vect[row][mid]>val)
        {
            high = mid-1;
        }
        else if(vect[row][mid]<val)
        {
            low = mid +1;
        }
    }
    return false;

    }
};
