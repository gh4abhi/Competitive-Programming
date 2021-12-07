// Problem Link - https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-minimum-moves-official/ojquestion

#include<bits/stdc++.h>
#define ll int
using namespace std;

int jumpT(int i, int n, vector<int>& jumps, vector<int>& dp)
{
    dp[n] = 1;
    for(ll i=n-1;i>=0;i--)
    {
        ll less = INT_MAX;
        for(ll j=1;j<=jumps[i];j++)
        {
            if(i+j>n)
            {
                break;
            }
            if(dp[i+j]==0)
            {
                continue;
            }
            less = min(less,dp[i+j]);
        }
        if(less!=0 and less!=INT_MAX)
        {
            dp[i] = 1+less;
        }
        
    }
    return max(0,dp[0]-1);
}

int main() {

  int n;
  cin >> n;

  vector<int> jumps(n);

  for (int i = 0; i < n; i++)
  {
    cin >> jumps[i];
  }

  vector<int> dp(n + 1, 0);

  int ans = jumpT(0, n, jumps, dp);

  if (ans < 30)
    cout << ans;
  else
    cout << "null";
}
