// Problem Link - https://leetcode.com/contest/weekly-contest-316/problems/determine-if-two-events-have-conflict/

#define ll int

class Solution {
public:
    bool check(vector<string> event1, vector<string> event2)
    {
        ll s1h = stoi(event1[0].substr(0,2));
        ll s1m = stoi(event1[0].substr(3,2));
        ll s2h = stoi(event2[0].substr(0,2));
        ll s2m = stoi(event2[0].substr(3,2));
        ll e1h = stoi(event1[1].substr(0,2));
        ll e1m = stoi(event1[1].substr(3,2));
        ll e2h = stoi(event2[1].substr(0,2));
        ll e2m = stoi(event2[1].substr(3,2));
        cout<<s1h<<" "<<s2h<<" "<<e2h<<endl;
        cout<<s1m<<" "<<s2m<<" "<<e2m<<endl;
        if(s1h>s2h and s1h<e2h)
            return 1;
        if(s1h==e2h and s1h>=s2h)
            return s1m<=e2m;
        if(s1h==s2h and s1h<=e2h)
            return s1m>=s2m;
        return 0;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(check(event1,event2))
            return 1;
        if(check(event2,event1))
            return 1;
        return 0;
    }
};