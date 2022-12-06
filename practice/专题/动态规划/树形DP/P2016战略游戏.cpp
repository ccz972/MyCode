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
  
  vector<vector<int> > son(n);
  
  for(int i = 0; i < n; i ++ ) {
    int now; cin >> now;
    int k; cin >> k;
    for(int j = 0; j < k; j ++ ) {
      int x; cin >> x;
      son[now].push_back(x);
      son[x].push_back(now);
    }
  }

  vector<array<int, 2> > f(n);
  
  function<void(int, int)> dfs = [&](int u, int fa) {
    f[u][1] = 1;
    for (auto& v : son[u]) if(v != fa) {
      dfs(v, u);
      f[u][0] += f[v][1];
      f[u][1] += min(f[v][0], f[v][1]);
    }
  };

  dfs(0, -1);
  // cout << f[0][0] << " " << f[1][1] << "\n";
  cout << min(f[0][0], f[0][1]);
  return 0;
}