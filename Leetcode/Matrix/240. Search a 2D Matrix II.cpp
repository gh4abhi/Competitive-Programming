// Problem Link - https://leetcode.com/problems/search-a-2d-matrix-ii/

#define ll int

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& vect, int val) {
        ll n = vect.size();
        ll m = vect[0].size();
        
        ll r = 0, c = m-1;
        
        while(r<n and c>=0)
        {
            if(vect[r][c]==val)
                return true;
            else if(vect[r][c]>val)
                c--;
            else if(vect[r][c]<val)
                r++;
        }
        return false;
    }
};
