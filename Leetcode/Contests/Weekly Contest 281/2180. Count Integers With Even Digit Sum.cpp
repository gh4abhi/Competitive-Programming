// Problem Link - https://leetcode.com/contest/weekly-contest-281/problems/count-integers-with-even-digit-sum/

#define ll int

class Solution {
public:
    int countEven(int num) {
            ll ans = 0;
        for(ll i=1;i<=num;i++)
        {
            ll t = i;
            ll sum = 0;
            while(t)
            {
                sum += t%10;
                t=t/10;
            }
            if(sum%2==0)
                ans++;
        }
        return ans;
    }
};