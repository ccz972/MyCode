// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")

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
  int n; cin >> n;
  vector son(n, vector<pair<int, int> >());
  vector<int> deg(n);
  for(int u = 0, v, w; u < n; u ++ ) {
    cin >> v >> w;  -- v;
    son[u].emplace_back(v, w);
    son[v].emplace_back(u, w);
    deg[u] ++; deg[v] ++;
  }
  // debug(deg);
  vector<int> q(n << 1);
  vector<int> st(n);
  int hh = 0, tt = -1;
  for(int i = 0; i < n; i ++ ) if(deg[i] == 1) {
    q[++ tt] = i;
    st[i] = true;
  }
  
  while(hh <= tt) {
    int u = q[hh ++ ];
    for(auto& [v, w]: son[u]) if(!st[v]) {
      if(-- deg[v] == 1) {
        q[++ tt] = v;
        st[v] = true;
      }
    }
  }

  vector<ll> f(n, 0), g(n, 0), other(n, 0);

  function<ll(int, int)> dfs1 = [&] (int u, int fa) {
    ll ret = 0;
    for(auto& [v, w]: son[u]) if(v != fa && deg[v] == 1) {
      chkmax(ret, dfs1(v, u));
      if(f[v] + w >= f[u]) {
        g[u] = f[u];
        f[u] = f[v] + w;
      } else {
        chkmax(g[u], f[v] + w);
      }
    }
    chkmax(ret, f[u] + g[u]);
    return ret;
  };
  
  for(int i = 0; i < n; i ++ ) if(deg[i] != 1) {
    other[i] = dfs1(i, -1);
  }

  ll ans = 0, mx = 0;
  vector<int> a, b; //存储环上的点，用于单调队列DP | 路径长度

  function<void(int)> find = [&] (int u) {
    
    for(auto& [v, w] : son[u]) if(-- deg[v] == 1) {
      a.emplace_back(v);
      b.emplace_back(w);
      chkmax(mx, other[v]);
      find(v);
    }
  };
  
  for(int i = 0; i < n; i ++ ) if(deg[i] == 2) {
    -- deg[i];
    a.clear(), b.clear();  
    mx = 0;
    chkmax(mx, other[i]);
    a.emplace_back(i);
    find(i);
    int cnt = a.size();
    if(a.size() == 2) {
      for(auto& [v, w]: son[a.back()]) if(v == i && w != b.back()) {
        b.emplace_back(w);  break;
      }
    } else {
      for(auto&[v, w]: son[a.back()]) if(v == i) {
        b.emplace_back(w);  break;
      }
    }
    int m = a.size();
    for(int j = 0; j < m; j ++ ) a.emplace_back(a[j]);
    m = b.size();
    for(int j = 0; j < m - 1; j ++ ) b.emplace_back(b[j]);
    m = b.size();
    vector<ll> s(m + 1);
    for(int j = 0; j < m; j ++ ) {
      s[j + 1] = s[j] + b[j];
    }

    hh = 0, tt = -1;
    m = a.size();
    
    for(int j = 0; j < m; j ++ ) {
      if(hh <= tt && j - q[hh] >= cnt) ++ hh;
      if(hh > tt) {
        chkmax(mx, f[a[j]]);
      } else {
        chkmax(mx, f[a[j]] + s[j] - s[q[hh]] + f[a[q[hh]]]);
      } 
      while(hh <= tt && f[a[j]] - s[j] >= f[a[q[tt]]] - s[q[tt]]) -- tt;
      q[++ tt] = j;
    }
    ans += mx;
  }

  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}