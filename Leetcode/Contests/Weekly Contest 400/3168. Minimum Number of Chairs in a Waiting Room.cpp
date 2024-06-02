// Problem Link - https://leetcode.com/contest/weekly-contest-400/problems/minimum-number-of-chairs-in-a-waiting-room/

#define ll int

class Solution {
public:
    int minimumChairs(string s) {
        ll ans = 0, c = 0;
        for(auto i:s)
        {
            if(i=='E')
            {
                if(c==0)
                    ans += 1;
                else
                    c--;
            }
            else
                c++;
        }
        return ans;
    }
};