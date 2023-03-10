// Problem Link - https://leetcode.com/contest/weekly-contest-307/problems/largest-palindromic-number/

#define ll long long

class Solution {
public:
    string largestPalindromic(string num) {
        map<ll,ll> m;
        ll count = 0;
        for(auto i:num)
        {
            if(i=='0')
                m[-(i-'0')]++;
            else
                m[-(i-'0')]++,count++;
        }
        if(count==0)
            return "0";
        if(count==1)
        {
            string ans = "";
            for(auto i:num)
            {
                if(i!='0')
                {
                    ans += i;
                    return ans;
                }    
            }
        }
        map<ll,ll> op;
        ll ok = 1;
        for(auto i:m)
        {
            if(i.second>1)
            {
                if(i.second&1 and ok)
                {
                    op[i.first] = i.second;
                    ok = 0;
                }
                else
                {
                    if(i.second&1)
                        op[i.first] = i.second-1;
                    else
                        op[i.first] = i.second;
                }
            }
            else if(ok)
            {
                op[i.first] = i.second;
                ok = 0;
            }
        }
        string str1 = "", str2 = "";
        char ch = '$';
        for(auto &i:op)
        {
            char x = (abs(i.first)+'0');
            if(i.first=='@')
                x = '0';
            if(i.second&1)
                ch = x, i.second-=1;
            if(i.second)
            {
                while(i.second)
                {
                    str1 += x;
                    str2 += x;
                    i.second-=2;
                }
            }
        }
        reverse(str2.begin(),str2.end());
        string ans = "";
        ans += str1;
        if(ch!='$')
            ans += ch;
        ans += str2;
        count = 0;
        for(auto i:ans)
            if(i!='0')
                count++, ch = i;
        string a = "";
        if(count==1)
            return a + ch;
        return ans;
    }
};