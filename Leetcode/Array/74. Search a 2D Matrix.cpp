// Problem Link - https://leetcode.com/problems/search-a-2d-matrix/

#define ll int

class Solution {
public:
    ll searchMatrixHelper(vector<vector<int>>& matrix, int target)
    {
        ll m = matrix.size();
        ll n = matrix[0].size();
        for(ll i=0;i<m;i++)
        {
            if(target>=matrix[i][0] and target<=matrix[i][n-1])
            {
                return i;
            }
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[matrix.size()-1][matrix[0].size()-1]<target)
        {
            return false;
        }
       ll row = searchMatrixHelper(matrix, target);
        
        ll m = matrix.size();
        ll n = matrix[0].size();
       ll low = 0;
       ll high = n-1;
       ll mid = 0;
        if(matrix[row][low]==target or matrix[row][high]==target)
        {
            return true;
        }
       while(low<high)
       {
           mid = (low+high)/2;
           if(matrix[row][mid]==target)
           {
               return true;
           }
           else if(matrix[row][mid]>=target)
           {
               high = mid;
           }
           else
           {
               low = mid + 1;
           }
           if(low==high)
           {
                if(matrix[row][high]==target)
           {
               return true;
           }
           }
       }
        return false;
    }
};
