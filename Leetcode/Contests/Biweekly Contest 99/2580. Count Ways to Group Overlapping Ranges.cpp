// Problem Link - https://leetcode.com/contest/biweekly-contest-99/problems/count-ways-to-group-overlapping-ranges/

#define ll int
#define MOD 1000000007

class Solution {
public:
    
    int countWays(vector<vector<int>>& vect) {
        sort(vect.begin(),vect.end(),[](vector<ll>& a, vector<ll> &b){
            if(a[0]!=b[0])
                return a[0]<b[0];
            return a[1]<b[1];
        });
        ll count = 1;
        ll op = vect[0][1];
        for(ll i=1;i<vect.size();i++)
        {
            if(vect[i][0]<=op)
                op = max(op,vect[i][1]);
            else
                count++, op = vect[i][1];
        }
        ll ans = 1;
        for(ll i=0;i<count;i++)
            ans = (ans*2)%MOD;
        return ans;
    }
};