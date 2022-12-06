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
#define int long long
constexpr int N = 510;
constexpr int M = 1E5 + 10;

struct node {
  int u, v, w;
} edge[M];

int dist[N][N]; // backup[N];
int val[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    edge[i] = {u, v, w};
  }

  memset(dist, 0x3f, sizeof dist);
  dist[0][1] = 0;

  for (int i = 1; i < n; i ++ ) {
    memcpy(dist[i], dist[i - 1], sizeof dist[i]);
    for (int j = 0; j < m; j ++ ) {
      auto [u, v, w] = edge[j];
      if (dist[i][u] > dist[i - 1][v] + w) {
        dist[i][u] = dist[i - 1][v] + w;
      }
      swap(u, v);
      if (dist[i][u] > dist[i - 1][v] + w) {
        dist[i][u] = dist[i - 1][v] + w;
      }
    }
  }

  // for (int i = 1; i < n - 1; i ++ ) {
  //   for (int j = 1; j <= n; j ++ ) {
  //     cout << dist[i][j] << " \n"[j == n];
  //   }
  // }

  int q; cin >> q;
  while (q -- ) {
    int t; cin >> t;
    for (int i = 1; i < n; i ++ ) cin >> val[i];
    for (int i = 2; i < n; i ++ ) val[i] += val[i - 1];
    int ans = dist[1][t] + val[1];
    for (int i = 2; i < n; i ++ ) {
      chkmin(ans, dist[i][t] + val[i]);
    }
    cout << ans << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}