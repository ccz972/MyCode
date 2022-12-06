#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
  vector<int> w(n); for(int &x: w) cin >> x;
  vector son(n, vector<int>());
  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
  }
  while(true) {
    bool flag = true;
    for(int i = 0; i < n; i ++ ) if(w[i] != 0) {
      flag = false;
    }
    if(flag) break;
    auto now = w;
    for(int i = 0; i < n; i ++ ) if(now[i]) {
      -- w[i];
      for(auto v: son[i]) {
        ++ w[v];
      }
    }
    debug(w);
  }

}
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  freopen("E.txt", "w", stdout);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
