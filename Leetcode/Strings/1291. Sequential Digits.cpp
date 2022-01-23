// Problem Link - https://leetcode.com/problems/sequential-digits/

#define ll int

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        ll lower = to_string(low).length();
        ll upper = to_string(high).length();
        vector<ll> ans;
        string str = "123456789";
        for(ll i=lower;i<=upper;i++)
        {
            for(ll j=0;j<(10-i);j++)
            {
                ll val = stoi(str.substr(j,i));
                if(val>=low and val<=high)
                {
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};
