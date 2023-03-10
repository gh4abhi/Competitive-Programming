// Problem Link - https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#define ll int

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<ll> vis(26,0);
        for(auto i:sentence)
            vis[i-'a'] = 1;
        for(auto i:vis)
            if(i==0)
                return false;
        return true;
    }
};