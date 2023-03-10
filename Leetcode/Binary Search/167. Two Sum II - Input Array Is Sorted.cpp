// Problem Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#define ll long long

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vect;
        for(ll i=0;i<numbers.size();i++)
        {
            ll val = numbers[i];
            ll op = target - numbers[i];
            ll ok = numbers[i] + target;
            ll ans = -1;
            if(op>=numbers[i])
            {
                ans = lower_bound(numbers.begin()+i+1,numbers.end(),op)-numbers.begin();
                if(ans>=numbers.size())
                    ans = -1;
                else if(numbers[ans]!=op or op + numbers[i]!=target)
                    ans = -1;
            }
            if(ok>=numbers[i] and ans == -1)
            {
                ans = lower_bound(numbers.begin()+i+1,numbers.end(),ok)-numbers.begin();
                if(ans>=numbers.size())
                    ans = -1;
                else if(numbers[ans]!=ok or ok+numbers[i]!=target)
                    ans = -1;
            }
            if(ans!=-1 and ans<numbers.size())
            {vect.push_back(i+1);
                vect.push_back(ans+1);
                break;
            }
        }
        return vect;
    }
};