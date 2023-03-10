#define ll int

bool solve(int n) {
    ll sum = 0;
    ll val = n;
    ll count = 0;
    vector<ll> vect;
    while(val)
    {
        ll r = val%10;
        sum+=r;
        vect.push_back(r);
        val/=10;
        count++;
    }
    sum = 0 ;
    for(auto i:vect)
    {
        ll pro = 1;
        ll c = count;
        while(c--)
        pro*=i;
        sum+=pro;
    }
    return sum==n;    
}
