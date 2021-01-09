// Problem Link - https://codeforces.com/gym/311184/problem/A

#include <bits/stdc++.h>
#define ll long long
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pb push_back
#define vec  vector<ll>
#define pi vector<pair<ll,ll>>
#define fi first
#define se second
#define pb push_back
#define sz size()
#define pt1(a) cout<<a<<" ";
#define pt2(a,b) cout<<a<<" "<<b<<" ";
#define pt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define sorti(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define eb emplace_back
#define mp make_pair
#define MOD 1000000007
 
using namespace std;

ll visited[210000]={0}; 
vector<ll>vg[210000];

void printv(vector<ll> v)   // Primt Vector
{
   for(auto x:v)
   cout<<x<<" ";
}
 
bool isPrime(ll n)   // Check Prime
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
 
ll fact(ll n)   // Calculate Factorial
{
    ll p=1;
    for(ll i=1;i<=n;i++)
    p*=i;
    return p;
}

// IO File
void IO()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}  

// Multiplicative Inverse
 
ll power(ll x, unsigned ll y, unsigned ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 


ll modInverse(ll a,ll m) 
{ 
     return power(a, m - 2, m); 
     
} 

vector<ll> primeFactors(ll n) 
{ 
    vec v2;
	// Print the number of 2s that divide n 
	while (n % 2 == 0) 
	{ 
	    v2.pb(2);
		//cout << 2 << " "; 
		n = n/2; 
	} 
 
	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2) 
	for (ll i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		// While i divides n, print i and divide n 
		while (n % i == 0) 
		{ 
		    v2.pb(i);			//cout << i << " "; 
			n = n/i; 
		} 
	} 
 
	// This condition is to handle the case when n 
	// is a prime number greater than 2 
	if (n > 2) 
	v2.pb(n);
		//cout << n << " "; 
		return v2;
} 

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
void its_Function()
{
    ll n,sumo=0,sume=0,poso=0,pose=0,t=0,m=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        if(a&1)
        {
            sumo++;
        }
        if(!(a&1))
        {
            sume++;
        }
        if(sumo == 1 and t!=1)
        {
            t=1;
            poso = i+1;
        }
        if(sume == 1 and m!=1){
            pose = i+1;
            m=1;
        }
    }
    if(sumo<sume)
    {
        cout<<poso;
    }
    else
    {
        cout<<pose;
    }
}
 
int main()
{   
 
	BOOST;
    its_Function();
	return 0;
	
}
