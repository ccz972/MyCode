//lqmm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;

constexpr int N = 210;

int n, m, q; 

int g[N][N];


void solve() {
  cin >> n >> m >> q;
  memset(g, 0x3f, sizeof g);
  for (int i = 0; i < m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  rep(i, 1, n) g[i][i] = 0;
  for (int k = 1; k <= n; k ++ ) {
    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= n; j ++ ) {
        chkmin(g[i][j], min(g[i][k] + g[k][j], g[j][k] + g[k][i] ));
      }
    }
  }

  while (q -- ) {
    int op, u, v; cin >> op >> u >> v;
    if (op == 1) {
      cout << g[u][v] << "\n";
    } else {
      int w; cin >> w; //u->v（v->u) = w
      if (w >= g[u][v]) continue;
      g[u][v] = g[v][u] = w;
      rep(i, 1, n) {
        rep(j, 1, n) {
          chkmin(g[i][j], g[i][u] + g[u][j]);
        }
      }
      rep(i, 1, n) {
        rep(j, 1, n) {
          chkmin(g[i][j], g[i][v] + g[v][j]);
        }
      }
    }
  }

}

void solve2() {
  cin >> n >> m >> q;
  memset(g, 0x3f, sizeof g);
  for (int i = 0; i < m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  rep(i, 1, n) g[i][i] = 0;
  for (int k = 1; k <= n; k ++ ) {
    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= n; j ++ ) {
        chkmin(g[i][j], min(g[i][k] + g[k][j], g[j][k] + g[k][i] ));
      }
    }
  }
  bool flag = false;
  while (q -- ) {
    int op, u, v; cin >> op >> u >> v;
    if (op == 1) {
      if (flag) {
        flag = false;
        for (int k = 1; k <= n; k ++ ) {
          for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
              chkmin(g[i][j], min(g[i][k] + g[k][j], g[j][k] + g[k][i] ));
            }
          }
        }
      }
      cout << g[u][v] << "\n";
    } else {
      int w; cin >> w; //u->v（v->u) = w
      if (w >= g[u][v]) continue;
      g[u][v] = g[v][u] = w;
      flag = true;
    }
  }

}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve2();
  return 0;
}