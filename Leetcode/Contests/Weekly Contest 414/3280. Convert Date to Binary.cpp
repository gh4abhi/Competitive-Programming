// Problem Link - https://leetcode.com/problems/convert-date-to-binary/description/

#define ll int

class Solution {
public:
    
    string bin(ll x)
    {
        ll ans = 0;
        string op  = "";
        while(x)
        {
            ll r = x%2;
            op = to_string(r) + op;
            x = x/2;
        }
        return op;
    }
    
    string convertDateToBinary(string date) {
        ll year = stoi(date.substr(0,4));
        ll month = stoi(date.substr(5,2));
        ll day = stoi(date.substr(8,2));
        string a = bin(year);
        string b = bin(month);
        string c = bin(day);
        string ans = a + "-" + b + "-" + c;
        return ans;
    }
};