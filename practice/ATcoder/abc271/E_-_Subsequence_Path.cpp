#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, m, k; 
  cin >> n >> m >> k;
  vector<ll> f(n + 1, 1E18);
  f[1] = 0;
  vector<array<int, 3> > e(m);
  for (int i = 0; i < m; i ++ ) {
    for (int j = 0; j < 3; j ++ ) {
      cin >> e[i][j];
    }
  }
  for (int i = 0; i < k; i ++ ) {
    int x; cin >> x; -- x;
    auto [u, v, w] = e[x];
    chkmin(f[v], f[u] + w);
  }
  if (f[n] < 1E17) {
    cout << f[n] << "\n";
  } else {
    cout << "-1\n";
  }
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}