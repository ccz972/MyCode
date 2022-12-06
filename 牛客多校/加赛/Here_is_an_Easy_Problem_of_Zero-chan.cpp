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
  int n, q; cin >> n >> q;
  vector<vector<int>> son(n + 1);

  for (int i = 1, u, v; i < n; i++ ) {
    cin >> u >> v; 
    son[u].push_back(v), son[v].push_back(u);
  }

  vector<ll> s2(n + 1), s5(n + 1);
  vector<int> sz(n + 1);
  vector<ll> cnt2(n + 1), cnt5(n + 1);

  function<void(int, int)> dfs = [&] (int u, int fa) {
    sz[u] = 1; int now = u;
    while(~now & 1) cnt2[u] ++, now >>= 1;
    while(now % 5 == 0) cnt5[u] ++, now /= 5;
    for(auto&v : son[u]) if(v != fa) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  };  

  dfs(1, 0);

  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    
    for(auto&v : son[u]) if(v != fa) {
      s2[v] += cnt2[u] * (sz[u] - sz[v]);
      s5[v] += cnt5[u] * (sz[u] - sz[v]);
      dfs1(v, u);
    }
  };  

  function<void(int, int)> dfs2 = [&] (int u, int fa) {
    for(auto&v : son[u]) if(v != fa) {
      s2[v] += s2[u];
      s5[v] += s5[u];
      dfs2(v, u);
    }
  };  
  
  dfs1(1, 0);
  dfs2(1, 0); 
  for(int i = 1; i <= n; i ++ ) {
    s2[i] += cnt2[i] * sz[i];
    s5[i] += cnt5[i] * sz[i];
  }
  // debug(s2);
  // debug(s5);
  while(q -- ) {
    int x; cin >> x;
    cout << min(s2[x], s5[x]) << "\n";
    // cout << min(s2[x] + cnt2[x] * (sz[x]), s5[x] + cnt5[x] * (sz[x])) << "\n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}