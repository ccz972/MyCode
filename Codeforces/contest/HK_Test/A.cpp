#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  int n; cin >> n;
  vector<long long> a(n);
  for(auto &x: a) cin >> x;

  ll N = a[0];

  for(int i = 1; i < n; i ++ ) {
    if(N <= 0) {
      cout << "NO\n";
      return ;
    }
    N += a[i];
  }

  cout << "YES\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}