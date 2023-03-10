// Problem Link - https://leetcode.com/problems/determine-if-string-halves-are-alike/

#define ll int

class Solution {
public:
    bool halvesAreAlike(string str) {
        ll a= 0, b=0;
        ll i=str.length()/2-1;
        ll j = i+1;
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        while(i>=0)
        {
            if(s.find(tolower(str[i]))!=s.end())
                a+=1;
            if(s.find(tolower(str[j]))!=s.end())
                b+=1;
            i--;
            j++;
        }
        return a==b;
    }
};