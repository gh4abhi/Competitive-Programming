// Problem Link - https://leetcode.com/problems/triangle/

#define ll int

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        ll n = triangle.size();
        ll dp[n][n];
        for(ll i=0;i<n;i++)
        {
         for(ll j=0;j<n;j++)
          {
             if(i==n-1)
             {
                 do
             }
            dp[i][j] = INT_MAX;
           }   
        }
        
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=vect[i].size()-1;j>=0;j--)
            {
                dp[]
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0; j<n;j++)
            {
                if(dp[i][j]==INT_MAX)
                {
                    cout<<0<<" ";
                    continue;
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};
