// Problem Link - https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/count-occurrences-2-880cf6bd/

#include<bits/stdc++.h>
using namespace std;

string CountOccurrences (string S) {
   map<char,int> m;
   for(auto i: S)
   {
       m[i]++;
   }
    string ans;
  set<char> se;
  for(auto i:S)
  {
      if(se.find(i)==se.end())
      {
          se.insert(i);
          ans+=i;
          ans+=to_string(m[i]);
      }
  }
  return ans;
  }

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        string S;
        cin>>S;

        string out_;
        out_ = CountOccurrences(S);
        cout << out_;
        cout << "\n";
    }
}
