// Problem Link - https://leetcode.com/problems/next-greater-element-iii/

# define ll long long
class Solution {
public:
    int nextGreaterElement(int num) {
        string str = to_string(num);
        string temp = str;
        ll n = str.length();
        ll ans = 1e18;
        for(ll i=n-1;i>0;i--)
        {
            for(ll j=i-1;j>=0;j--)
            {
               temp = str;
               if(str[i]>str[j])
               {
                   swap(temp[i],temp[j]);
                   sort(temp.begin()+j+1,temp.end());
                   ll val = stoll(temp);
                   if(val<=INT_MAX and val>num)
                       ans = min(ans,val);
               }
            }
        }
        if(ans==1e18)
            return -1;
        return ans;
    }
};