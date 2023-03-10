// Problem Link - https://leetcode.com/problems/can-make-palindrome-from-substring/

#define ll int

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        ll n = s.length();
        vector<vector<ll>> m(n,vector<ll>(26,0));
        vector<bool> ans;
        for(ll i=0;i<n;i++)
        {
            if(i>0)
                m[i] = m[i-1];
            m[i][s[i]-'a']++;
        }
        for(auto i:queries)
        {
            ll ev = 0;
            ll od = 0;
            for(ll j=0;j<26;j++)
            {
                ll op = 0;
                if(i[0]!=0)
                    op = m[i[0]-1][j];
                if((m[i[1]][j]-op)&1)
                    od++;
                else
                    ev++;
            }
            while(i[2]--)
                od-=2;
            if(od<2)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};