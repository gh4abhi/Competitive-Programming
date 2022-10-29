/*-----------------------------------------------------------------
                    Always beleive you can.
-------------------------------------------------------------------*/

#include <bits/stdc++.h> 
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define prt1(a) cout<<a<<" ";
#define prt2(a,b) cout<<a<<" "<<b<<" ";
#define prt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define ll long long
#define vec  vector<ll>
#define pb push_back
#define pa vector<pair<ll,ll>>
#define fi first
#define se second
#define siz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007

using namespace std;

//----------------------------------------------------------------Necessary Functions---------------------------------------------------------------------------------------
void printvec(vector<ll> v) {
   for(auto x:v)
   cout<<x<<" ";
}
 
ll fact(ll n)   {
    ll m=1;
    for(ll i=1;i<=n;i++)
    m*=i;
    return m;
}

void io()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}  

ll lcm (ll a,ll b)
{
    return (a / __gcd(a, b)) * b;
}
 
ll power(ll x, unsigned ll y, unsigned ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll po = power(x, y / 2, m) % m; 
    po = (po * po) % m; 
  
    return (y % 2 == 0) ? po : (x * po) % m; 
} 

 
bool isPrime(ll n){ 
    if (n <= 1) 
        return false; 
  
      for (ll i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

ll modInverse(ll a,ll m) 
{ 
     return power(a, m - 2, m); 
     
} 

vector<ll> primeFactors(ll n) 
{ 
    vec v2;
	while (n % 2 == 0) 
	{ 
	    v2.pb(2);
		n = n/2; 
	} 
 
	for (ll i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		while (n % i == 0) 
		{ 
		    v2.pb(i);	
						n = n/i; 
		} 
	} 
 
	if (n > 2) 
	v2.pb(n);
		return v2;
} 

//------------------------------------------------------------------------------Code---------------------------------------------------------------------------------

void its_Function()
{
  ll n;
  cin>>n;
  vector<ll> vect(n);
  for(ll i=0;i<n;i++)
  {
      cin>>vect[i];
  }
  ll score_a = 0 , score_b = 0,j=0,k=0;
  sort(vect.begin(),vect.end(),greater<ll>());
  for(ll i =0;i<n;i++)
  {
     if(i%2==0)
     {
         if(vect[i]%2==0)
         {
             score_a+=vect[i];
         }
     }
     else
     {
         if(vect[i]&1)
         {
             score_b+=vect[i];
         }
     }
  }
  if(score_a>score_b)
  {
      cout<<"Alice";
  }
  else if(score_a<score_b)
  {
      cout<<"Bob";
  }
  else
  {
      cout<<"Tie";
  }
}
//--------------------------------------------------------------Main Function---------------------------------------------------------------------------------------------- 
int main()
{   
 
	BOOST;
	ll t;
	cin>>t;
	while(t--)
	{
    its_Function();
    cout<<"\n";
	}
	return 0;	
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

