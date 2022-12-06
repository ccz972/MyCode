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
  vector<int> w(n);
  for(int &x: w) cin >> x;
  
  vector<vector<int> > son(n);
  
  for(int i = 1; i < n; i ++ ) {
    int u, v;  cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
    son[v].push_back(u);
  }

  vector<array<int, 2> > f(n);
  
  function<void(int, int)> dfs = [&](int u, int fa) {
    f[u][1] = w[u];
    for (auto& v : son[u]) if(v != fa) {
      dfs(v, u);
      f[u][0] += max(f[v][0], f[v][1]);
      f[u][1] += f[v][0];
    }
  };

  dfs(0, -1);

  cout << max(f[0][0], f[0][1]);
  return 0;
}