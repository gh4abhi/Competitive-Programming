// Problem Link - https://leetcode.com/contest/weekly-contest-291/problems/remove-digit-from-number-to-maximize-result/

#define ll double

class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> ans;
        for(ll i=0;i<number.length();i++)
        {
            if(number[i]==digit)
            {
                string res = "";
                res += number.substr(0,i) + number.substr(i+1,number.length());
                ans.push_back(res);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];
    }
};