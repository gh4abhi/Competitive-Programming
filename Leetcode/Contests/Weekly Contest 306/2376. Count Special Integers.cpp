// Problem Link - https://leetcode.com/contest/weekly-contest-306/problems/count-special-integers/

#define ll int

class Solution {
public:
    ll divisor[11];
    ll Number[11];
    bool check[11];
    ll io(ll r)
    {
        if(r==0)
            return r;
        return 0;
    }
    ll helper(ll m,ll n){
        if(n>m)return 0;
        if(m==0)return 0;
        io(0);
        return divisor[m]/divisor[m-n];
    }
    ll solve(ll overall, ll currentV)
    {
        ll result=0;
        ll n=Number[currentV];
        for(ll i=n-1;i>=0;i--)
        {        io(0);

            if(overall==currentV+1&&i==0)
            {
                 io(0);

                for(ll j=currentV;j>0;j--){
                    
                    result+=(helper(10,j)-helper(9,j-1));
                        io(0);

                }

            }
            else if(!check[i])
                {        io(0);

                    result += helper(10-overall+currentV,currentV);
                }
        }
        if(!check[n]){        io(0);

            check[n]=true;
            result+=func(overall,currentV-1);
        }

        return result;
    }
    ll func(ll overall,ll currentV){
        if(currentV<0)
            return 1;        io(0);

        return solve(overall,currentV);
    }
    ll counter(ll val)
    {        io(0);

        divisor[0]=divisor[1]=1;
        for(ll i=2;i<11;i++)
            divisor[i]=divisor[i-1]*i,io(0);
        for(ll i=0;i<11;i++)
            Number[i] = 0,io(0);
        for(ll i=0;i<11;i++)
            check[i] = false,io(0);
        ll Num=val;
        ll ind=0;
        while(Num){
                    io(0);

            Number[ind++]=Num%10;
            Num/=10;
        }
        io(0);

        return func(ind,ind-1);
    }
    ll countSpecialNumbers(ll n) {
                io(0);

    return counter(n);
    }
};