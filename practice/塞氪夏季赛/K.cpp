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
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int> > > son(n);
  vector<bool> st(n);
  vector<int> col(n);
  for(int i = 0; i < m; i ++ ) {
    int u, v; string s; cin >> u >> v >> s;
    -- u, -- v;
    if(u == v) {
      if(s[0] != 'g') {
        cout << "-1\n";
        return 0;
      }
      continue;
    } 
    if(s[0] == 'g') {
      son[u].push_back({v, 1});
      son[v].push_back({u, 1});
    } else {
      son[u].push_back({v, 0});
      son[v].push_back({u, 0});
    }
  }

  

  function<bool(int, int)> dfs = [&] (int u, int fa) {
    st[u] = true;
    for(auto& [v, w]: son[u]) if(v != fa) {
      if(col[v]) {
        if(w && col[u] != col[v]) {
          return false;
        }  
        if(!w && col[u] == col[v]) {
          return false;
        }
      } else {
        col[v] = (w ? col[u] : 3 - col[u]);
        if(!dfs(v, u)) {
          return false;
        }
      }
    }
    return true; 
  };

  function<int(int, int, int)> dfs2 = [&] (int u, int fa, int c) {
    int now = (col[u] == c);
    for(auto& [v, w]: son[u]) if(v != fa) {
      now += dfs2(v, u, c);
    }
    return now;
  };

  int ans = 0;

  for(int i = 0; i < n; i ++ ) if(!col[i]) {
    col[i] = 1;
    bool f = dfs(i, -1);
    if(!f) {
      cout << "-1\n";
      return 0;
    }

    ans += max(dfs2(i, -1, 1), dfs2(i, -1, 2));

  }

  cout << ans << "\n";

  return 0;
}