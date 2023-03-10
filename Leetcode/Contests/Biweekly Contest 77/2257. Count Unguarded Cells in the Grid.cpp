// Problem Link - https://leetcode.com/contest/biweekly-contest-77/problems/count-unguarded-cells-in-the-grid/

#define ll long long

class Solution {
public:
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<ll>> vect(m,vector<ll>(n,0));
        for(auto i:guards)
            vect[i[0]][i[1]] = 1;
        for(auto i:walls)
            vect[i[0]][i[1]] = -1;
        for(ll i = 0;i<m;i++)
        {
            ll flag = 0;
            for(ll j=0;j<n;j++)
            {
                if(vect[i][j]==1)
                    flag = 1;
                else if(vect[i][j]==-1)
                    flag = 0;
                if(vect[i][j]!=1 and vect[i][j]!=-1)
                {
                    if(flag)
                        vect[i][j] = 2;
                }
            }
        }
        for(ll i = 0;i<m;i++)
        {
            ll flag = 0;
            for(ll j=n-1;j>=0;j--)
            {
                if(vect[i][j]==1)
                    flag = 1;
                else if(vect[i][j]==-1)
                    flag = 0;
                if(vect[i][j]!=1 and vect[i][j]!=-1)
                {
                    if(flag)
                        vect[i][j] = 2;
                }
            }
        }
        
        for(ll j=0;j<n;j++)
        {
            ll flag = 0;
            for(ll i=0;i<m;i++)
            {
                if(vect[i][j]==1)
                    flag = 1;
                else if(vect[i][j]==-1)
                    flag = 0;
                if(vect[i][j]!=1 and vect[i][j]!=-1)
                {
                    if(flag)
                        vect[i][j] = 2;
                }
            }
        }
        
         for(ll j=0;j<n;j++)
        {
            ll flag = 0;
            for(ll i=m-1;i>=0;i--)
            {
                if(vect[i][j]==1)
                    flag = 1;
                else if(vect[i][j]==-1)
                    flag = 0;
                if(vect[i][j]!=1 and vect[i][j]!=-1)
                {
                    if(flag)
                        vect[i][j] = 2;
                }
            }
        }
        
        ll count = 0;
        for(ll i=0;i<m;i++)
            for(ll j=0;j<n;j++)
                if(vect[i][j]==0)
                    count++;
        return (int)count;
    }
};