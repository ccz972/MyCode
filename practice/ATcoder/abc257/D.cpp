#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<array<int, 3 > > a(n);
  for(int i = 0; i < n; i ++ ) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  // vector f(n, vector<ll>(n, 1e18));
  vector f(n, vector<ll> (n, 1e18));

  auto get = [&] (array<int, 3> x, array<int, 3> y) {
    return 1ll * abs(x[0] - y[0]) + abs(x[1] - y[1]);
  };

  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++ ) if(i != j) {
      f[i][j] = (get(a[i], a[j]) + a[i][2] - 1) / a[i][2];
    } else {
      f[i][j] = 0;
    }
  }

  for(int k = 0; k < n; k ++ ) {
    for(int i = 0; i < n; i ++ ) {
      for(int j = 0; j < n; j ++ ) {
        f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
      }
    }
  }

  ll mx = 1e18;
  
  for(int i = 0; i < n; i ++ ) {
    mx = min(mx, *max_element(f[i].begin(), f[i].end()));
  }
  cout << mx << "\n";

  return 0;
}