// Problem Link - https://leetcode.com/contest/biweekly-contest-99/problems/split-with-minimum-sum/

#define ll int

class Solution {
public:
    ll mini(ll ind, ll a, ll b, string &op)
    {
        if(ind==op.length())
            return a + b;
        return min(mini(ind+1,a*10+(op[ind]-'0'),b,op),mini(ind+1,a,b*10+(op[ind]-'0'),op));
    }
    
    int splitNum(int num) {
        string op = "";
        ll n = num;
        while(n)
        {
            op += to_string(n%10);
            n/=10;
        }
        sort(op.begin(),op.end());
        return mini(0,0,0,op);
    }
};