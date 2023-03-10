// Problem Link - https://leetcode.com/contest/biweekly-contest-84/problems/task-scheduler-ii/

#define ll long long

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        ll wait = 0;
        ll pre = -1;
        ll ans = 0;
        map<ll,ll> m;
        for(ll i=0;i<tasks.size();i++)
        {
            if(m.count(tasks[i])!=0)
            {
                if(m[tasks[i]]>=ans-space)
                {
                    ans += (space - (ans-m[tasks[i]]))+1;
                }
                else
                    ans++;
            }
            else
                ans++;
            m[tasks[i]] = ans;
        }
        return ans;
    }
};