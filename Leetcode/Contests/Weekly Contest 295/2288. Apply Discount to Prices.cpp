// Problem Link - https://leetcode.com/contest/weekly-contest-295/problems/apply-discount-to-prices/

#define ll long long

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        vector<string> vect;
        string str = "";
        for(ll i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                vect.push_back(str);
                str="";
                continue;
            }
            str+=sentence[i];
        }
        vect.push_back(str);
        for(ll i=0;i<vect.size();i++)
        {
            string str = vect[i];
            if(vect[i][0]=='$')
            {
                string temp = "";
                ll ok = 1;
                ll dot = 0;
                for(ll j=1;j<vect[i].length();j++)
                {
                    ll dig = vect[i][j] -'0';
                  temp = temp + vect[i][j];
                    if(dig>=0 and dig<=9)
                        continue;
                    else
                        ok = 0;
                }
                if(!ok)
                    continue;
                if(temp.length()==0)
                    continue;
                ll val = stoll(temp);
                long double v1 = val*1.00;
                long double v2 = v1;
                long double dis = discount;
                v2*=(dis);
                v2 =(v2/100);
                v1-=v2;
                string st = to_string(v1);
                string trust = "";
                ll dot1 = 0;
                ll count = 0;
                for(auto k:st)
                {
                    if(dot1==1)
                        count++;
                    if(k=='.')
                    {
                        dot1 = 1;
                    }
                    if(dot1==1 and count>2)
                        break;
                    trust += k;
                }
                vect[i] = '$' + trust;
            }
        }
        string ans ="";
        for(auto i:vect)
            ans += i + ' ';
        return ans.substr(0,ans.length()-1);
    }
};