#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int> > s(n + 1), son(n + 1);
  for (int i = 1; i <= n; i ++ ) {
    int k; cin >> k; s[i].resize(k);
    for (int j = 0; j < k; j ++ ) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v), son[v].emplace_back(u);
  }
  




}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
