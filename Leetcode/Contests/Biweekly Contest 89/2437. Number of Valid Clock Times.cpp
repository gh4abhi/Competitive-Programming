// Problem Link - https://leetcode.com/contest/biweekly-contest-89/problems/number-of-valid-clock-times/

#define ll int

class Solution {
public:
    int countTime(string time) {
        ll ans = 0;
        map<pair<ll,ll>,ll> m;
        for(ll i=0;i<=2;i++)
        {
            for(ll j=0;j<=9;j++)
            {
                for(ll k=0;k<=5;k++)
                {
                    for(ll z = 0;z<=9;z++)
                    {
                        ll op = 0;
                        if(time[0]=='?')
                            op = i;
                        else
                            op = time[0]-'0';
                        if(time[1]=='?')
                            op = op*10 + j;
                        else
                            op = op*10 + (time[1]-'0');
                        ll op2 = 0;
                        if(time[3]=='?')
                            op2 = k;
                        else
                            op2 = time[3]-'0';
                        if(time[4]=='?')
                            op2 = op2*10 + z;
                        else
                            op2 = op2*10 + (time[4]-'0');
                        if(op>=0 and op<=23 and op2>=0 and op2<=59 and m.count({op,op2})==0)
                        {
                            m[{op,op2}]++;
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};