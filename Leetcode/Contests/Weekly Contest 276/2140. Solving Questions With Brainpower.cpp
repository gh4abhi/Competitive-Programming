// Problem Link - https://leetcode.com/contest/weekly-contest-276/problems/solving-questions-with-brainpower/

#define ll long long

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ll dp[questions.size()];
        for(ll i=0;i<questions.size();i++)
        {
            dp[i] = 0;
        }
        for(ll i = questions.size()-1;i>=0;i--)
        {
            
           dp[i] = questions[i][0];
           if(i==questions.size()-1)
           {
               continue;
           }
           ll ind = i+questions[i][1]+1;
           ll maxi = 0;
            if(ind<questions.size())
            {
                maxi = max(maxi,dp[ind]);
            }
            dp[i] += maxi;
            dp[i] = max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};
