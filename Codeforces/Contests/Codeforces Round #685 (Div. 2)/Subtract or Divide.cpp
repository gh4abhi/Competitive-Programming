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
 ll n,count=0;
 cin>>n;
   if(n==1 )
     {
         return n-1;
     }
     ll m =n;
 for(ll i =0;i<m/2;i++)
 {
     
     if(n&1)
     {
         count+=1;
         n  = n-1;
         
     }
     if(n==2)
     {
         return (count + 1);
     }
     if(!(n&1))
     {
         count+=1;
         ll r = n/2;
         n = n/r;
     }
     
 } 
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

