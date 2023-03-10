// Problem Link - https://leetcode.com/problems/longest-happy-string/

#define ll int

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        map<char,ll> m;
        m['a'] = a;
        m['b'] = b;
        m['c'] = c;
        string ans = "";
        vector<char> vect = {'a','b','c'};
        string prev = "dummy";
        while(m['a'] or m['b'] or m['c'])
        {
            ll n = ans.length();
            sort(vect.begin(),vect.end(),[&m](char &a, char &b){
                return m[a]>m[b];
            });
            if(ans.length()<2)
                ans += vect[0],m[vect[0]]--;
            else if(ans.length()>=2)
            {
                if(ans[n-2]== ans[n-1] and ans[n-1]==vect[0])
                {
                    if(m[vect[1]])
                        ans += vect[1], m[vect[1]]--;
                }
                else
                    ans += vect[0], m[vect[0]]--;
            }
            if(prev==ans)
                return ans;
            prev = ans;
        }
        return ans;
    }
};