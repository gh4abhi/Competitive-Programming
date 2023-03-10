// Problem Link - https://www.codingninjas.com/codestudio/problems/630512?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

ll DFS(ll** arr, ll n, ll m, ll i, ll j)
{
    arr[i][j] = -1;
    for(auto r:{1,-1})
    {
        for(auto c:{1,-1,0})
        {
            if(i+r>=0 and i+r<n and j+c>=0 and j+c<m and arr[i+r][j+c]==1)
                DFS(arr,n,m,i+r,j+c);
            if(i+c>=0 and i+c<n and j+r>=0 and j+r<m and arr[i+c][j+r]==1)
                DFS(arr,n,m,i+c,j+r);
        }
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    ll ans = 0;
   for(ll i=0;i<n;i++)
       for(ll j=0;j<m;j++)
           if(arr[i][j]==1)
               ans++, DFS(arr,n,m,i,j);
    return ans;
}
