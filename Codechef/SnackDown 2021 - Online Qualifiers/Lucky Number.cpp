// Problem Link - https://www.codechef.com/SNCKQL21/problems/LUCKYNUM

#include <iostream>
#define ll long long
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll a,b,c;
	    cin>>a>>b>>c;
	    if(a==7 or b==7 or c==7)
	    {
	        cout<<"YES";
	    }
	    else
	    {
	        cout<<"NO";
	    }
	    cout<<endl;
	}
	return 0;
}
