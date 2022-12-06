#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1E6 + 10;

int d[N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    d[u] ++, d[v] ++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i ++ ) if (d[i] == 1) {
    ++ ans;
  }
  if (n == 1) ans = 1;
  cout << ans;
  

  for (int i = 1; i <= n; i ++ ) {
    d[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    if (i != 1) cout << "\n";
    solve();
  }
  return 0;
}