// Problem Link - https://www.codechef.com/submit/TESTAVG

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
    double a,b,c;
    cin>>a>>b>>c;
    if((a+b)/2.0<35)
    {
        cout<<"Fail\n";
        continue;
    }      
    if((c+b)/2.0<35)
    {
        cout<<"Fail\n";
        continue;
    }      
    if((a+c)/2.0<35)
    {
        cout<<"Fail\n";
        continue;
    }      
    cout<<"Pass\n";
    }
    return 0;
}