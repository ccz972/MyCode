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
// constexpr int N = 2E5 + 10;

void solve() {
  int n, m; cin >> n >> m;
  int a, b, x, y; cin >> a >> b >> x >> y;
  vector<int> dx{0, 0, -1, 1}, dy{-1, 1, 0, 0};
  vector<vector<int> > g(n + 1, vector<int>(m + 1));
  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> g[i][j];
    }
  }

  queue<pair<int, int> > q;
  vector<vector<int> > dist(n + 1, vector<int>(m + 1, INF));
  dist[a][b] = 0;
  q.push({a, b});
  while(!q.empty()) {
    auto t = q.front(); q.pop();
    auto [px, py] = t;
    if (px == x && py == y) {
      cout << dist[px][py] << "\n";
      return ;
    }
    for (int i = 0; i < 4; i ++ ) {
      auto [nx, ny] = t;
      nx += dx[i], ny += dy[i];
      if (nx < 1 || nx > n || ny < 0 || ny > m) continue;
      if (g[nx][ny] == 1) continue;
      if (dist[nx][ny] > dist[t.first][t.second] + 1) {
        dist[nx][ny] = dist[t.first][t.second] + 1;
        q.push({nx, ny});
      }
    }
  }


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}