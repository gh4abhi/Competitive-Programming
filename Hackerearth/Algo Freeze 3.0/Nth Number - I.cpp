// Problem Link - https://www.hackerearth.com/problem/algorithm/hp-and-nth-number-408fb73b/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}
long long solve (long long a, long long b, long long N) {
   // Write your code here

ll lcma = lcm(a,b);

return lcma*N;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        long long a;
        cin >> a;
        long long b;
        cin >> b;
        long long N;
        cin >> N;

        long long out_;
        out_ = solve(a, b, N);
        cout << out_;
        cout << "\n";
    }
}
