// Problem Link - https://leetcode.com/contest/weekly-contest-294/problems/minimum-lines-to-represent-a-line-chart/

#define ll long long

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end());
        ll count = 0;
        ll flag = 0;
        ll n = stockPrices.size();
        vector<int> pre(2);
        pre = stockPrices[0];
        map<string,ll> m;
        string prev = "";
        for(ll i=1;i<n;i++)
        {
            string str = "";
            ll num1 = (stockPrices[i][1] - pre[1]);
            ll num2 = (stockPrices[i][0] - pre[0]);
            ll div = __gcd(num1,num2);
            num1/=div;
            num2/=div;
            string slope = to_string(num1) + "/" + to_string(num2);
            ll val = (pre[1]*num2 - (num1)*pre[0]);
            string inter = to_string(val) + "/" + to_string(num2);
            
            str = (slope) + "*x" + "+" + inter;
            if(prev!=str)
                count++;
            prev = str;
            pre = stockPrices[i];
        }
        return (int)count;
    }
};