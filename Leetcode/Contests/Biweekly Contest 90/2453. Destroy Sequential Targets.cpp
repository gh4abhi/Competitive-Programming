// Problem Link - https://leetcode.com/contest/biweekly-contest-90/problems/destroy-sequential-targets/

#define ll int

class Solution {
public:
    ll io(ll op)
    {
        return op;
    }
    void make(map<ll,ll> &m, vector<ll> &nums, ll space)
    {
        for(int i=0;i<nums.size();i++)
            {
        io(0);
        io(0);
                    ll op = nums[i]/space;
                    op = nums[i]-op*space;
        io(0);
        io(0);
                    if(op==0)
                        op=space;
                    m[op]++;
                   
            }
    }
    ll findOK(map<ll,ll> &m, ll &ok)
    {
        io(0);

        for(auto i: m)
                if(i.second>ok)
                    ok = i.second;
        return ok;
    }
    
    ll result(map<ll,ll> &m, vector<ll> &nums, ll space,set<ll> &ans)
    {
         int mini = INT_MAX;
             for(int i=0;i<nums.size();i++)
            {
                    int op = nums[i]/space;
                    op = nums[i]-op*space;
                    if(op==0) 
                        op=space;
                   
                    if(ans.find(op)!=ans.end())
                    {
                            if(mini>nums[i])
                                    mini =nums[i];
                            io(0);
}
        io(0);
                   
            }
        return mini;
    }
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        io(0);
        map<int,int>m;
        make(m,nums,space);     
            ll ok=-1;
            findOK(m,ok);
           set<ll>ans;
            for(auto i : m)
                if(i.second==ok)
                        io(0),ans.insert(i.first);
           
            return result(m,nums,space,ans);            
    }
};