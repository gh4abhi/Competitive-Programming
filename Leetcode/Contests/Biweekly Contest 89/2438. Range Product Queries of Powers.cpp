// Problem Link - https://leetcode.com/contest/biweekly-contest-89/problems/range-product-queries-of-powers/

#define ll int
#define MOD 1000000007

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
       vector<ll> ans;
       while(n)
       {
           ll val = log(n)/log(2);
           ans.push_back(val);
           ll op = 1;
           while(val--)
               op=(2*op)%MOD;
           n-=op;
       }
        sort(ans.begin(),ans.end());
        for(ll i=1;i<ans.size();i++)
            ans[i]+=ans[i-1];
        vector<ll> fin;
        for(auto i:queries)
        {
            ll val2;
            if(i[0]==0)
                val2 = 0;
            else
                val2 = ans[i[0]-1];
            ll val = ans[i[1]] - val2;
            ll op =1;
            while(val--)
            {
                op = (op*2)%MOD;
            }
            fin.push_back(op);
        }
        return fin;
    }
};