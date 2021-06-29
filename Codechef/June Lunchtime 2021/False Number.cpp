#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        if(str[0]>49)
        {
            cout<<1<<str;
        }
        else
        {
            for(ll i=0;i<str.length();i++)
            {
                if(i==1)
                {
                    cout<<0;
                    
                }
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
}
