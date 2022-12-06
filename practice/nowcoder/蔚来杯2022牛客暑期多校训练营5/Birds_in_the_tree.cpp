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

constexpr int p = 1E9 + 7;
  //h[u]代表 u 的子树中，并且选u的所有的非u叶子合法的方案数
  //h[u] *= (h[v] + (a[v] == col))
  //f[u] = \sigma{f[v]} + g[u] , 
  // if(a[u] == col) 
  //   f[u] *= (h[v] + 1)

void solve() {
  int n; cin >> n;
  vector<int> a(n); 
  string s; cin >> s;
  for(int i = 0; i < n; i ++ ) {
    a[i] = s[i] - '0';
  }
  vector<vector<int>> son(n);
  for (int i = 1, u, v; i < n; i++ ) {
    cin >> u >> v; u --, v --;
    son[u].push_back(v), son[v].push_back(u);
  }
  

  /*
  f[u]表示 u 的子树中的所有合法方案数

  g[u] 表示u的子树中(不包含u)的叶子的所有合法方案数


  */


 /*
  f[u]表示 u 的子树中的所有合法方案数

  g[u] 表示u的子树中(不包含u)的叶子的所有合法方案数


  */
  vector<ll> f(n), g(n), h(n);
  //f[u] 
  function<void(int, int, int)> dfs = [&] (int u, int fa, int col) {
    int cnt = 0;

    // f[u] = g[u] = h[u] = 1;
    g[u] = 1; h[u] = 1;

    if(a[u] == col) {
      for(auto& v: son[u]) if(v != fa) {
        dfs(v, u, col);
        f[u] += f[v]; f[u] %= p;
        g[u] *= (h[v] + 1); g[u] %= p;
        h[u] *= (h[v] + 1); h[u] %= p;
        ++ cnt;
      }
      f[u] += g[u]; f[u] %= p;

    } else {
      for(auto& v: son[u]) if(v != fa) {
        dfs(v, u, col);
        f[u] += f[v]; f[u] %= p;
        g[u] *= (g[v] + 1); g[u] %= p;
        h[u] *= (h[v] + 1); h[u] %= p;
        ++ cnt;
      }

      // g[u] --; 
      // h[u] --; 
      for(auto &v: son[u]) if(v != fa) {
        g[u] -= g[v];
        g[u] %= p;
      }
      g[u] --; h[u] --;
      g[u] = (g[u] % p + p) % p;
      h[u] = (h[u] % p + p) % p;
      f[u] += g[u]; f[u] %= p;

    }

    if(!cnt) {
      f[u] = g[u] = h[u] = (a[u] == col);
    }  

  };

  dfs(0, -1, 1);
  ll ans = f[0];
  // debug(f);
  // debug(g);
  // debug(h);
  // cout << ans << "\n";
  for(int i = 0; i < n; i ++ ) {
    f[i] = g[i] = h[i] = 0;
  }
  
  dfs(0, -1, 0);

  ans += f[0];
  ans %= p;

  cout << ans << "\n";


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}