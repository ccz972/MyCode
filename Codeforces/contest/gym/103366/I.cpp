#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;
constexpr int M = 2E5 + 10;

int n, q, id, x; 
int val[N];
int h[N], e[M], ne[M], w[M], idx;
long long f[N], g[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dfs1(int u, int fa) {
  f[u] = val[u];
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i]; if (v != fa) {
      dfs1(v, u);
      chkmin(f[u], f[v] + w[i]);
    }
  }
}

void dfs2(int u, int fa) {
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i]; if (v != fa) {
      chkmin(f[v], f[u] + w[i]);
      dfs2(v, u);
    }
  }
}

void solve() {
  memset(h, -1, sizeof h);
  cin >> n >> q;
  for (int i = 1; i <= n; i ++ ) cin >> val[i];
  
  for (int i = 1; i < n; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    add(u, v, w); add(v, u, w);
  }

  while (q -- ) {
    int op; cin >> op;
    switch (op) {
    case 1:
      cin >> id >> x; 
      val[id] = x;
      break;

    case 2:
      cin >> id >> x;  -- id;
      w[id << 1] = w[id << 1 | 1] = x;
      break;

    case 3:
      dfs1(1, 0);
      dfs2(1, 0);
      long long ans = 0;
      for (int i = 1; i <= n; i ++ ) ans ^= f[i];
      cout << ans << "\n";  
      break;
    }
  }


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
