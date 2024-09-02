// Problem Link - https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

#define ll long long

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = 0;
        for(auto i:chalk)
            sum+=i;
        ll op = k/sum;
        ll r = k - sum*op;
        for(ll i=0;i<chalk.size();i++)
        {
            if(r<chalk[i])
                return i;
            r -= chalk[i];
        }
        return 0;
    }
};