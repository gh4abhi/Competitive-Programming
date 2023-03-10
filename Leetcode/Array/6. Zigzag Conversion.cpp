// Problem Link - https://leetcode.com/problems/zigzag-conversion/

#define ll int

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string str = "";
        ll val = numRows + (numRows-2);
        for(ll i=0;i<numRows;i++)
        {
            ll k = i;
            if(i==0)
                while(k<s.length())
                    str += s[k],k+=numRows + (numRows-2);
            else if(i==numRows-1)
                while(k<s.length())
                    str += s[k],k+=numRows + (numRows-2);
            else
            {
                ll op = val;
                while(k<s.length())
                    str += s[k], k+=op, op = abs((numRows + numRows - 2) - op);
            }
            val-=2;
        }
        return str; 
    }
};