// Problem Link - https://leetcode.com/problems/find-missing-observations/

#define ll int

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ll m = rolls.size();
        ll sum = mean*(m+n);
        ll sumn = 0;
        for(auto i :rolls)
            sumn += i;
        ll rem = sum - sumn;
        
        vector<ll> ans;
        if(rem<0)
            return ans;
        sum = 0;
        double check = (rem*1.0)/n;
        ll val = rem/n;
        if(check>6 or check<1)
            return ans;
        for(ll i= 0;i<n-1;i++)
            ans.push_back(val);
        ll last = rem - (n-1)*val;
        if(last>6)
        {
            last = last - 6;
            for(ll i = 0; i <ans.size(); i++)
            {
                ll add = min(last,6-ans[i]);
                last-=add;
                ans[i]+=add;
                if(last==0)
                    break;
        }}
        else{
            ans.push_back(last);
            return ans;
        }
        vector<ll>temp;
        if(last!=0)
            return temp;
        ans.push_back(6) ;
        return ans;
    }
};