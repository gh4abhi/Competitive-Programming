// Problem Link - https://codeforces.com/contest/1454/problem/B

#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pb push_back
 
using namespace std;
 
bool isPrime(ll n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (ll i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
 
 
ll its_Function()
{
 ll n,mini;
 cin>>n;
 map<int,pair<int,int>> m;
 for(ll i =0;i<n;i++)
 {
     ll a;
     cin>>a;
     m[a].first = i+1;
     m[a].second++;
 }
 for(auto const & i: m)
    {
      if(i.second.second == 1)
      {
          return i.second.first;
      }
    }
 return -1;
}
 
int main()
{   
 
	BOOST;
	ll t,res;
	cin>>t;
	while(t--)
	{
    res = its_Function();
	cout<<res<<"\n";
	}
	return 0;
	
}

