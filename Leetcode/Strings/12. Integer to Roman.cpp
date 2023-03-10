// Problem Link - https://leetcode.com/problems/integer-to-roman/

#define ll long long

class Solution {
public:
    string intToRoman(int num) {
        vector<ll> intCode = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> code = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        for(ll i=0;i<intCode.size();i++)
            while(intCode[i]<=num)
                ans += code[i], num -= intCode[i];
        return ans;
    }
};