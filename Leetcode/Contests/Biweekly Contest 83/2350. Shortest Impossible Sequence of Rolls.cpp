// Problem Link - https://leetcode.com/contest/biweekly-contest-83/problems/shortest-impossible-sequence-of-rolls/

#define ll long long

class Solution {
public:
    void io(ll r)
    {
        if(r==0)
            return;
    }
    ll solve(vector<int>& rolls, int k)
    {
        multiset<int>st;
        ll index=0, result=1;
        while(1) {
            io(0);
            ll count =0, tempi=0;
            st.clear();
            for(ll i=index; i<rolls.size(); i++) {
                if(st.find(rolls[i]) == st.end())
                {
                    io(0);
                    st.insert(rolls[i]);
                    count++;
                    tempi=max(tempi, i);
                    if(st.size() == k) break;
                }
                io(0);
            }
            if(count < k) return result;
            index=tempi+1;
            result++;
        }
    }
    int shortestSequence(vector<int>& rolls, int k) {
       return (int)solve(rolls,k);
    }
};