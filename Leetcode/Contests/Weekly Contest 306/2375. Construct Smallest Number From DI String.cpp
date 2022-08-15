// Problem Link - https://leetcode.com/contest/weekly-contest-306/problems/construct-smallest-number-from-di-string/

#define ll int

class Solution {
public:
    vector<string> vect;
    void small(string pattern, string ans, ll i, vector<ll> &vis)
    {
        vis[ans[ans.length()-1]-'0'] = 1;
        if(i==pattern.length())
        {
            if(ans.length()==pattern.length()+1)
                vect.push_back(ans);
            return;
        }
        if(pattern[i]=='I')
        {
            ll val = ans[ans.length()-1]-'0';
            for(ll j=val+1;j<10;j++)
            {
                if(vis[j]==0)
                small(pattern,ans+to_string(j),i+1,vis);
            }
        }
        else
        {
            ll val = ans[ans.length()-1]-'0';
            for(ll j=val-1;j>0;j--)
            {
                if(vis[j]==0)
                small(pattern,ans+to_string(j),i+1,vis);
            }
        }
        vis[ans[ans.length()-1]-'0'] = 0;
    }
    
    string smallestNumber(string pattern) {
        string ans = "";
        vector<ll> vis(20,0);
        for(ll i=1;i<10;i++)
        {
            small(pattern,ans+to_string(i),0,vis);
        }
        sort(vect.begin(),vect.end());
        return vect[0];
    }
};