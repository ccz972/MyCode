#include <bits/stdc++.h>
// #include <debugger>

using namespace std;

constexpr int inf = 1e9;

void solve() {
  int n; scanf("%d", &n);

  vector<int> a(n);
  for(int &x: a) scanf("%d", &x);
  
  vector son(n, vector<int>());
  for(int i = 1; i < n; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[u].push_back(v);
    son[v].push_back(u);
  }
  
  vector<int> f(n, -inf), g(n, inf);

  function<void(int, int)> dfs = [&] (int u, int fa) {
    for(int &v: son[u]) if(v != fa) {
      dfs(v, u);
      f[u] = max(f[u], min(a[u] < a[v] ? f[v] :  inf, a[u] < g[v] ? a[v] :  inf));
      g[u] = min(g[u], max(a[u] > a[v] ? g[v] : -inf, a[u] > f[v] ? a[v] : -inf));
      debug(a[u], a[v], f[v], g[v]);
    }
  };
  
  dfs(0, -1);

  if(f[0] != inf || g[0] != -inf) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}

int main() {
  solve();
  return 0;
}

/*

jlaskdjaskldjlksajdkl
jsakldjaslkdjkslajdklasjdkljsakldsakljdkl
*/