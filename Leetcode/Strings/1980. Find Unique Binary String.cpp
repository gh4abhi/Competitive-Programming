// Problem Link - https://leetcode.com/problems/find-unique-binary-string/

#define ll long long

class Solution {
public:
    map<string,ll> m;
    string backTrack(string ans, ll i)
    {
        if(m.count(ans)==0)
            return ans; 
        for(ll j = i;j<ans.length();j++)
        {
            string temp = ans;
            if(temp[j]=='0')
                temp[j]='1';
            else
                temp[j] = '0';
            string tA = backTrack(temp,i+1);
            if(tA!="null")
                return tA;
        }
        return "null";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto i:nums)
            m[i]++;
        string ans = string(nums.size(),'0');
        return backTrack(ans,0);
    }
};