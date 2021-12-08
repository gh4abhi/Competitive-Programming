// Problem Link - https://leetcode.com/problems/sort-colors/

#define ll int

class Solution {
public:
    void sortColors(vector<int>& nums) {
        ll zero=0,one=0,two=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                zero++;
            }
            else if(i==1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        ll sum = one+two+zero;
        for(ll i=0;i<sum;i++)
        {
            cout<<i<<" ";
            if(zero!=0)
            {
              nums[i]=0;
                zero--;
            }
            else if(one!=0)
            {
                // cout<<1<<"-"<<i<<" "<<one<<endl;
                nums[i] = 1;
                one--;
            }
            else
            {
                nums[i] = 2;
                two--;
            }
        }
    }
};
