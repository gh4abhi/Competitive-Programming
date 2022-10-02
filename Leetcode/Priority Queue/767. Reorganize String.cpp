// Problem Link - https://leetcode.com/problems/reorganize-string/

#define ll int

class Solution {
public:
    string reorganizeString(string s) {
        vector<ll> m(26,0);
        ll maxi = 0;
        for(auto i:s)
            m[i-'a']+=1, maxi = max(maxi,m[i-'a']);
        string ans = "";
        ll op = s.length();
        ll ok = op;
        if(op&1)
            ok++;
        if(maxi>ok/2)
            return ans;
        priority_queue<pair<ll,char>> pq;
        for(ll i=0;i<26;i++)
            if(m[i])
                pq.push({m[i],char(i+'a')});
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            if(ans.length() and cur.second==ans.back())
            {
                auto c = pq.top();
                pq.pop();
                pq.push(cur);
                cur=c;
            }
            ans += cur.second;
            cur.first-=1;
            if(cur.first>0)
                pq.push(cur);
        }
        return ans;
    }
};