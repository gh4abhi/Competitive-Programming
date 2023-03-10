// Problem Link - https://leetcode.com/contest/biweekly-contest-75/problems/minimum-bit-flips-to-convert-number/

#define ll int

class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<ll> vect1, vect2;
        while(start or goal)
        {
            vect1.push_back(start%2);
            vect2.push_back(goal%2);
            start/=2;
            goal/=2;
        }
        ll count =0;
        for(ll i=0;i<vect1.size();i++)
        {
            if(vect1[i]!=vect2[i])
                count++;
        }return count;
    }
};