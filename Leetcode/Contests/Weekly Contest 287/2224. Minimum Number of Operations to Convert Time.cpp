// Problem Link - https://leetcode.com/contest/weekly-contest-287/problems/minimum-number-of-operations-to-convert-time/

#define ll int

class Solution {
public:
    int convertTime(string current, string correct) {
        ll cur1 = stoi(current.substr(0,2));
        ll cor1 = stoi(correct.substr(0,2));
        if(cor1==0 and cur1>cor1)
            cor1 = 24;
        ll ans = 0;
        ll cur2 = stoi(current.substr(3,2));
        ll cor2 = stoi(correct.substr(3,2));
        cur2 += cur1*60;
        cor2 += cor1*60;
        ll diff = max(cor2 - cur2,0);
        ans += diff/60;
        diff -= (diff/60)*60;
        ans += diff/15;
        diff -= (diff/15)*15;
        ans += diff/5;
        diff -= (diff/5)*5;
        ans += diff;
        return ans;
    }
};