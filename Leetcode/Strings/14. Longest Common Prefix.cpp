// Problem Link - https://leetcode.com/problems/longest-common-prefix/

#define ll long long

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string valid = strs[0];
        for(ll i=1;i<strs.size();i++)
        {
            string op = "";
            for(ll j=0;j<strs[i].length();j++)
            {
                if(strs[i][j]==valid[j])
                    op+=valid[j];
                else
                    break;
            }
            valid = op;
        }
        return valid;
    }
};