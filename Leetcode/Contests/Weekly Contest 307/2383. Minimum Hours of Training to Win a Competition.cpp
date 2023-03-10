// Problem Link - https://leetcode.com/contest/weekly-contest-307/problems/minimum-hours-of-training-to-win-a-competition/

#define ll long long

class Solution {
public:
    int minNumberOfHours(int eng, int exp, vector<int>& energy, vector<int>& experience) {
        ll ans = 0;
        ll sum = 0;
        for(auto i:energy)
            sum += i;
        if(sum>=eng)
            ans += (sum - eng + 1);
        for(auto i:experience)
        {
            if(i>=exp)
                ans += (i-exp+1), exp += (i-exp+1);
            exp += i;
        }
        return ans;
    }
};