// Problem Link - https://leetcode.com/problems/find-the-town-judge/

#define ll int

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<ll> vect(n+1,0);
        for(ll i=0;i<trust.size();i++)
        {
            vect[trust[i][0]]--;
            vect[trust[i][1]]++;
        }
        
        for(ll i=1;i<=n;i++)
        {
            if(vect[i]==n-1)
                return i;
        }
        return -1;
    }
};
