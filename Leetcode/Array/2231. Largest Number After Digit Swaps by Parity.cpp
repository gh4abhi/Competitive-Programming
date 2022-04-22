// Problem Link - https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

#define ll int

class Solution {
public:
    int largestInteger(int num) {
        string eS = "", oS = "", ans =  "";
        string str = to_string(num);
        for(ll i=0;i<str.length();i++)
        {
            ll val = str[i] - '0';
            if(val&1)
                oS += str[i];
            else
                eS += str[i];
        }
        sort(oS.begin(),oS.end());
        reverse(oS.begin(),oS.end());
        sort(eS.begin(),eS.end());
        reverse(eS.begin(),eS.end());
        ll k1 = 0, k2 = 0;
        for(ll i=0;i<str.length();i++)
        {
            ll val = str[i] - '0';
            if(val&1)
                ans += oS[k1++];
            else
                ans += eS[k2++];
        }
        
        ll fAns = stoi(ans);
        return fAns;
    }
};