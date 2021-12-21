// Problem Link - https://leetcode.com/problems/consecutive-characters/

#define ll int
class Solution {
public:
    int maxPower(string s) {
        ll power = 0;
        ll curPower = 0;
        for(ll i=1; i<s.length(); i++)
            {
            
            if(s[i]==s[i-1])
                {
                curPower++;
                }else{
                curPower=0;
            }
            power=max(power,curPower);
        }
        return power+1;
    }
};
