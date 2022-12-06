#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> d(n);
  for(int &x: d) cin >> x;

  vector<vector<pair<int, int> > > son(n);

  for(int i = 0; i < n - 1; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    -- u, -- v;
    son[u].push_back(make_pair(v, w));
    son[v].push_back(make_pair(u, w));
  }
  
  vector<array<ll, 2> > f(n);

  function<void(int, int)> dfs = [&](int u, int fa) {
    vector<ll> now;
    for (auto& [v, w] : son[u]) if(v != fa) {
      dfs(v, u);
      f[u][0] += f[v][0];
      f[u][1] += f[v][0];
      now.push_back(max(0ll, f[v][1] + w - f[v][0]));
    }
    sort(now.begin(), now.end());
    reverse(now.begin(), now.end());
    for(int i = 0; i < now.size() && i < d[u]; i ++ ) {
      f[u][0] += now[i];
    }
    if(!d[u]) {
      f[u][1] = -1e18;
    } else {
      for(int i = 0; i < now.size() && i < d[u] - 1; i ++ ) {
        f[u][1] += now[i];
      } 
    }
    // debug(u, f[u][0], f[u][1]);
  };

  dfs(0, -1);

  cout << max(f[0][0], f[0][1]);

  return 0;
}