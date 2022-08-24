// Problem Link - https://www.codechef.com/submit/CANDYDIST?tab=statement

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if((a%b!=0) or (a%b==0 and ((a/b)&1)))
        cout<<"No";
        else
        cout<<"Yes";
        cout<<endl;
    }
    return 0;
}