// Problem Link - https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/cut-the-building-f64b52b5/

#include<bits/stdc++.h>
using namespace std;

vector <int> Solve(int N, vector<int> A, int K, vector <int> h) {
    vector<int> ans;
    sort(A.begin(),A.end());
  for(int i=0;i<K;i++)
  {
      int val = h[i];
      int count = 0;
      for(int j=0;j<N;j++)
      {
          if(A[j]>val)
          {
              count++;
          }
      }
      ans.push_back(count);
  }
  return ans;
  }

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N;
    vector <int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> K;
    vector <int> h(K);
    for (int i = 0; i < K; ++i) {
        cin >> h[i];
    }
    vector <int> out = Solve(N, A, K, h);
    for (int i = 0; i < int(out.size()); i++) {
        cout << out[i] << '\n';
    }
}
