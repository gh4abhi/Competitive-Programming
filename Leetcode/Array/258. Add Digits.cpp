// Problem Link - https://leetcode.com/problems/add-digits/

#define ll int

class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        ll sum = 0;
        ll u = 10;
        while(str.length()!=1)
        {
            ll val = 0;
            ll p = 1;
            while(num)
            {
                ll r = num%10;
                val += r;
                p = 10;
                num = num/10;
            }
            num = val;
            str = to_string(num);
        }
        ll ans = stoi(str);
        return ans;
    }
};
