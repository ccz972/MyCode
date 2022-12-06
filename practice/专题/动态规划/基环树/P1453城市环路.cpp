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
  vector<int> p(n); for(int &x: p) cin >> x;
  vector<vector<int>> son(n);
  vector<int> d(n);
  for (int i = 1, u, v; i <= n; i++ ) {
    cin >> u >> v; //u --, v --;
    son[u].push_back(v), son[v].push_back(u);
    d[u] ++, d[v] ++;
  }
  double k; cin >> k;
  vector<int> q(n + 2);
  vector<bool> st(n);
  int hh = 0, tt = -1; 
  for(int i = 0; i < n; i ++ ) if(d[i] == 1) {
    q[++ tt] = i;
    st[i] = true;
  }
  while(hh <= tt) {
    int u = q[hh ++];
    d[u] --;
    // debug(u);
    for(int& v: son[u]) {
      if(-- d[v] == 1) {
        q[++ tt] = v;
        st[v] = true;
      }
    }
  }
  int root, nroot;

  int ans = 0;
  vector<array<int, 2> > f(n);

  function<void(int, int)> dfs = [&](int u, int fa) {
    f[u][1] = p[u];
    f[u][0] = 0;
    for (auto& v : son[u]) if(v != fa) {
      if(u == root && v == nroot) continue;
      if(v == root && u == nroot) continue;
      dfs(v, u);
      f[u][0] += max(f[v][1], f[v][0]);
      f[u][1] += f[v][0];
    }
  };

  for(int i = 0; i < n; i ++ ) if(!st[i]) {
    root = i;
    for(int &v: son[root]) if(!st[v]) {
      nroot = v;
      break;
    }
    
    dfs(root, -1);

    chkmax(ans, f[root][0]);
    p[nroot] = -1e9;
    dfs(root, -1);
    chkmax(ans, max(f[root][0], f[root][1]));
  
    break;
  }

  k *= ans;

  cout << fixed << setprecision(1) << k << "\n";  

  return 0;
}