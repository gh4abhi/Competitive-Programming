// Problem Link - https://www.codingninjas.com/codestudio/problems/1112621?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

vector<ll> prefixFunction(string p)
{
    ll n = p.length();
    vector<ll> prefix(n,0);
    for(ll i=1;i<n;i++)
    {
        ll j = prefix[i-1];
        while(j>0 and p[i]!=p[j])
            j = prefix[j-1];
        if(p[i]==p[j])
            j++;
        prefix[i] = j;
    }
    return prefix;
}

bool kmpAlgo(string p, string s)
{
    vector<ll> prefix = prefixFunction(p);
    ll m = s.length();
    ll n = p.length();
    ll pos = -1;
    ll i=0, j = 0;
    while(i<m)
    {
        if(s[i]==p[j])
            i++,j++;
        else
        {
            if(j!=0)
                j = prefix[j-1];
            else
                i++;
        }
        if(j==n)
        {
            pos = i-n;
            break;
        }
    }
    return pos>-1;
}

bool findPattern(string p, string s)
{
    return kmpAlgo(p,s);
}