// Problem Link - https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#define ll int

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<ll,ll> m;
        for(auto i:tasks)
            m[i]++;
        ll ans = 0;
        for(auto i:m)
        {
            ll op = i.second;
            if(op==1)
                return -1;
            else if(op%3==0)
                ans += op/3;
            else if(op%3==2)
                ans += op/3 + 1;
            else if(op%3==1)
                ans += (op/3-1) + 2;
            else if(op%2==1)
                ans += (op/2-1) + 1;
            else if(op%2==0)
                ans += op/2;
            else 
                return -1;
        }
        return ans;
    }
};