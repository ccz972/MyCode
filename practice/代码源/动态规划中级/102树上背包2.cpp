#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)
#define YES cout << "YES" << "\n"; return  
#define NO  cout << "NO" << "\n";  return  
#define int ll
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

const int N = 50010, M = 110, inf = 1e12;

int n, q, w[N], sz[N], tmp[M], f[N][M];

vector<int> son[N];

void dfs(int u) {
  for(int &v: son[u]) {
    dfs(v);
    rep(i, 0, min(sz[u] + sz[v], 100ll)) tmp[i] = -inf;
    rep(i, 0, min(sz[u], 100ll)) {
      rep(j, 0, min(sz[v], 100ll - i)) {
        chkmax(tmp[i + j], f[u][i] + f[v][j]);
      }
    }
    sz[u] += sz[v];
    rep(i, 0, min(sz[u], 100ll)) f[u][i] = tmp[i];
  }  
  sz[u] ++;
  dec(i, min(sz[u], 100ll), 1) f[u][i] = f[u][i - 1] + w[u];
}

void solve() {
  cin >> n >> q;
  rep(i, 2, n) {
    int x; cin >> x;
    son[x].push_back(i);
  }
  rep(i, 1, n) cin >> w[i];
  dfs(1);
  while(q -- ) {
    int u, m; cin >> u >> m;
    cout << f[u][m] << "\n"; 
  }
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}