// Problem Link - https://leetcode.com/contest/biweekly-contest-79/problems/sender-with-largest-word-count/

#define ll long long

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,ll> m;
        ll n = messages.size();
        ll maxi = 0;
        for(ll i=0;i<n;i++)
        {
            ll val = 1;
            for(auto i:messages[i])
                if(i==' ')
                    val+=1;
            m[senders[i]]+=val;
            maxi = max(m[senders[i]],maxi);
        }
        vector<string> vect;
        for(auto i:m)
        {
            if(i.second==maxi)
                vect.push_back(i.first);
        }
        sort(vect.begin(),vect.end());
        return vect[vect.size()-1];
    }
};