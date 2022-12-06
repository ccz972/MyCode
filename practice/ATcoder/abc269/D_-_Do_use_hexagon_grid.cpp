#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 2010;

int g[N][N];
bool vis[N][N];
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};
void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i ++ ) {
    int x, y; cin >> x >> y;
    x += 1000, y += 1000;
    vis[x][y] = true;
  }
  int ans = 0;
  int m = 2000; //-1000 + 1000
  for (int i = 0; i <= m; i ++ ) {
    for (int j = 0; j <= m; j ++ ) if (vis[i][j]) {
      vis[i][j] = false;
      queue<pair<int, int> > q;
      q.push({i, j});
      while (q.size()) {
        auto t = q.front(); q.pop();
        for (int k = 0; k < 6; k ++ ) {
          auto [nx, ny] = t;
          nx += dx[k], ny += dy[k];
          if (nx < 0 || nx > m || ny < 0 || ny > m) continue;
          if (vis[nx][ny]) {
            q.push({nx, ny});
            vis[nx][ny] = false;
          }
        }
      }
      ++ ans;
    }
  }
  cout << ans << "\n";

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
