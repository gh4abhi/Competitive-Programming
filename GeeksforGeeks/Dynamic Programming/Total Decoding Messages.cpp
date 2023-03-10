// Problem Link - https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1

#define ll int
#define MOD 1000000007

class Solution {
    public:
        ll dp[1000000];
        ll count(ll ind, string &str)
        {
            if(ind==str.length())
                return 1;
            string op = "";
            op += str[ind];
            ll ans = 0;
            if(dp[ind]!=-1)
                return dp[ind];
            if(stoi(op)>=1 and stoi(op)<=26)
                ans = (ans + count(ind+1,str))%MOD;
            if(stoi(op)>=1 and stoi(op)<=26 and ind+1<str.length())
            {
                op += str[ind+1];
                if(stoi(op)>=1 and stoi(op)<=26)
                    ans = (ans + count(ind+2,str))%MOD;
            }
            return dp[ind] = ans;
        }
        
        
        int CountWays(string str){
            memset(dp,-1,sizeof(dp));
            return count(0,str);
        }

};