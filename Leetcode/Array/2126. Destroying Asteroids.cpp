// Problem Link - https://leetcode.com/problems/destroying-asteroids/

#define ll long long

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        ll sum = mass;
        for(ll i=0;i<asteroids.size();i++)
        {
            if(sum<asteroids[i])
                return false;
            sum += asteroids[i];
        }
        return true;
    }
};