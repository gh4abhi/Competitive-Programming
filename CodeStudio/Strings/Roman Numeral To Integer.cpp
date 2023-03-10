// Problem Link - https://www.codingninjas.com/codestudio/problems/981308?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int
int romanToInt(string s) {
    map<char,ll> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        ll ans = 0;
        for(ll i=0;i<s.length()-1;i++)
        {
            if(m[s[i]]<m[s[i+1]])
                ans-=m[s[i]];
            else
                ans+=m[s[i]];
        }
        ans += m[s[s.length()-1]];
        return ans;
}
