// Problem Link - https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/

#define ll int

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        ll ind = 0;
        for(ll i=0;i<s.length();i++)
        {
            ll m = k-1, j = i+1;
            string str = "";
            str += s[i];
            while(m--)
            {
                if(j<s.length())
                {
                    str += s[j];
                    j++;
                    i++;
                }
                else
                {
                    str += fill;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};
