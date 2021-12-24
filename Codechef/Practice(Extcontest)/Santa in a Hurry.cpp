// Problem Link - https://www.codechef.com/problems/SANHURRY

#include<bits/stdc++.h>
#define ll long long
#include <iostream>
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    for(ll i=0;i<n;i++)
	    {
	        ll a;
	        cin>>a;
	        ll flag = 0;
	        ll m = a%2;
	        ll prevA = !m;
	        while(a)
	        {
	            if(prevA==!m)
	            {
	                prevA = m;
	                a = a/2;
	                m = a%2;
	            }
	            else
	            {
	                flag = 1;
	                cout<<"Sack B";
	                break;
	            }
	        }
	        if(!flag)
	        {
	            cout<<"Sack A";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}

