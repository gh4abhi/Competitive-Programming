// Problem Link - https://codeforces.com/contest/1454/problem/A

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
 ll n;
 cin>>n;
 map<int ,int> m;
 
 vector<ll>vect(n),temp;
 for(ll i =0;i<n;i++)
 {
     cin>>vect[i];
     m[vect[i]] = 1;
 }
 if(count(vect.begin(),vect.end(),vect[0])==n)
 {
     return 0;
 }
   m[vect[n-1]]-=1;
  
 for(ll i =1;i<n;i++)
 {
     if(vect[i-1]!=vect[i])
     {
     m[vect[i]]++;
     }
 }
 ll mini = m[vect[n-1]] ;
 for(auto i :m)
 {
     ll x = i.second;
     mini = min(mini,x);
 }
 return mini;
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

