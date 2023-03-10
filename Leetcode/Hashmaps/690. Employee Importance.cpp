// Problem Link - https://leetcode.com/problems/employee-importance/

/*#define ll int

class Solution {
public:
    
    ll sum = 0;
    map<ll,Employee*> m;
    void DFS(Employee* emp)
    {
        sum += emp->importance;
        if(emp->subordinates.size()==0)
        {
            return;
        }
        for(auto j:emp->subordinates)
        {
            DFS(m[j]);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
       for(auto i:employees)
           m[i->id] = i;
        for(auto i:employees)
        {
            if(i->id==id)
            {
                DFS(i);
                break;
            }
        }
        return sum;
    }
};*/

// Tree Method


#include <bits/stdc++.h>
#define BOOST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define empb emplace_back
#define mpr make_pair
#define sortit(v) sort(v.begin(), v.end())
#define forl(n) for(ll i=0;i<n;i++)
#define prtIn(vect,i) cout<<vect[i]
#define vecs(vect,n) vector<ll> vect(n)
#define rev(v) reverse(v.begin(), v.end());
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
#define sz size()
#define full(a) a.begin(),a.end()
#define max_val INT_MIN
#define min_val INT_MAX;
#define MOD 1000000007
using namespace std;


map<char,ll> ans;

ll DFS(char ch, map<char,vector<char>> m)
 {
   if(m.count(ch)==0)
   {
     ans[ch] = 0;
     return 1;
   }
   ll val = 0; 
   for(auto i:m[ch])
   {
     val += DFS(i,m);
   }

   ans[ch] = val;
   return (val+1);
 }

int main()
{
   ll n;
 cin>>n;
 map<char, vector<char>> m;
 char ceo;
 for(ll i=0;i<n;i++)
 {
   char a,b;
   cin>>a>>b;
   if(a==b)
    ceo = b;
   else
    m[b].pb(a); 
 }

  ans[ceo] = DFS(ceo,m)-1;
  for(auto i:ans)
  {
        cout<<i.first<<" "<<i.second<<endl;
  }

return 0;
    
}