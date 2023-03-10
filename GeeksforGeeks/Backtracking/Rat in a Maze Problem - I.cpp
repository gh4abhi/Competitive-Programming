// Problem Link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

#define ll int
class Solution{
    public:
    
    vector<string> ans;
    
    void findPathHelper(vector<vector<int>> &m, int n, ll i, ll j, string str)
    {
        ll val = m[i][j];
        if(val==0)
            return;
        if(i==n-1 and j==n-1)
        {
            ans.push_back(str);
            return;
        }
        
        m[i][j] = -1;
        if(i>0 and m[i-1][j]!=-1)
        {
            findPathHelper(m,n,i-1,j,str + 'U');
        }
        if(i<n-1 and m[i+1][j]!=-1)
        {
            findPathHelper(m,n,i+1,j,str + 'D');
        }
        if(j>0 and m[i][j-1]!=-1)
        {
            findPathHelper(m,n,i,j-1,str + 'L');
        }
        if(j<n-1 and m[i][j+1]!=-1)
        {
            findPathHelper(m,n,i,j+1,str + 'R');
        }
        m[i][j] = val;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        findPathHelper(m,n,0,0,"");
        return ans;
    }
};
