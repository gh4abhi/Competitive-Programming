// Problem Link - https://leetcode.com/contest/biweekly-contest-93/problems/maximum-value-of-a-string-in-an-array/

#define ll int

class Solution {
public:
    int maximumValue(vector<string>& strs) {
        ll ans = INT_MIN;
        for(auto i:strs)
        {   
            ll num = 0;
            for(auto j:i)
            {
                if(j>='0' and j<='9')
                    num = num*10 + (j-'0');
                else
                {
                    num = i.length();
                    break;
                }
            }
            ans = max(ans,num);
        }
        return ans;
    }
};