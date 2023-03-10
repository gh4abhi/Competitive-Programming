// Problem Link - https://leetcode.com/problems/maximum-69-number/

#define ll int

class Solution {
public:
    int maximum69Number (int num) {
        string op = to_string(num);
        ll flag = 1;
        for(auto &i:op)
            if(i=='6' and flag)
                i='9', flag = 0;
        ll ans = stoi(op);
        return ans;
    }
};