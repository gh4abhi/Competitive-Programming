// Problem Link - https://leetcode.com/contest/weekly-contest-305/problems/check-if-there-is-a-valid-partition-for-the-array/

#define ll int

class Solution {
public:
    void io(ll r)
    {
        if(r==0)
            return;
    }
    bool part(vector<int>& vect)
    {
         ll n=vect.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        dp[1]=false;
        ll i = 2;
        while(i<=n){
            io(0);
            if(i==2){
                if(vect[i-1]==vect[i-2] and dp[i-2])
                    dp[i]=true;
            }
            else{
                if(vect[i-1]==vect[i-2] and dp[i-2])
                    dp[i]=true;
                
                if(vect[i-1]==vect[i-2] and vect[i-1]==vect[i-3] and dp[i-3])
                    dp[i]=true;
                            io(0);

                
                if(vect[i-1]-vect[i-2]==1 and vect[i-1]-vect[i-3]==2 and dp[i-3])
                    dp[i]=true;
            }
            i++;
        }
        return dp[n];
    }
    bool validPartition(vector<int>& vect) {
                    io(0);

       return part(vect);
    }
};