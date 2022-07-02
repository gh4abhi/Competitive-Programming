// Problem Link - https://www.codingninjas.com/codestudio/problems/house-robber_839733?leftPanelTab=0

#define ll long long
long long int houseRobber(vector<int>& valueInHouse)
{
    ll n = valueInHouse.size();
    if(n==1)
        return valueInHouse[0];
    if(n==2)
        return max(valueInHouse[0],valueInHouse[1]);
    if(n==3)
        return max(valueInHouse[2],max(valueInHouse[0],valueInHouse[1]));
    ll a = valueInHouse[n-1];
    ll b = valueInHouse[n-2];
    b = max(b,a);
    for(ll i=n-3;i>=1;i--)
    {
        ll cur;
        cur = max(b,valueInHouse[i]+a);
        a = b;
        b = cur;
    }
    ll ans = b;
    a = valueInHouse[0];
    b = valueInHouse[1];
    b = max(a,b);
    for(ll i=2;i<n-1;i++)
    {
        ll cur;
        cur = max(b,valueInHouse[i]+a);
        a = b;
        b = cur;
    }
    return max(ans,b);
}