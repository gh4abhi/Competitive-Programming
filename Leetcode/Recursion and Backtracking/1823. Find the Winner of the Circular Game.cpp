// Problem Link - https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#define ll int

class Solution {
public:
   
    ll JosephusProblem(ll n, ll k)
    {
        if(n==1)
            return 0;
        ll x = JosephusProblem(n-1,k);
        ll y = (x+k)%n;
        return y;
    }
    
    int findTheWinner(int n, int k) {
        return JosephusProblem(n,k)+1;
    }
};
