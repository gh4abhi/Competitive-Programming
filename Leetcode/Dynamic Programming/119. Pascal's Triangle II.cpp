// Problem Link - https://leetcode.com/problems/pascals-triangle-ii/

#define ll int

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<ll> temp;
        vector<ll> dp;
        dp.push_back(1);
        for(ll i=1;i<=rowIndex;i++)
        {
            temp = dp;
            for(ll j=0;j<=i;j++)
            {
                ll op = 0;
                if(j>0)
                    op += temp[j-1];
                if(j<i)
                    op += temp[j];
                if(j==i)
                    dp.push_back(op);
                else
                    dp[j] = op;
            }
        }
        return dp;
    }
};