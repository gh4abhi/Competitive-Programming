// Problem Link - https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

#define ll int

vector<ll> prefixFunction(string &p)
{
    ll m = p.length();
    vector<ll> prefix(m,0);
    prefix[0] = 0;
    for(ll i=1;i<m;i++)
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

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(),B.end());
    string p = A + "$" + B;
    vector<ll> prefix = prefixFunction(p);
    return A.length()-prefix[p.length()-1];
}
