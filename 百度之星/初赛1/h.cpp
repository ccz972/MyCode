#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for (int i = (b); i <= (s); ++i)
#define dec(i, b, s) for (int i = (b); i >= (s); --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T>
void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
void chkmin(T &x, T y) {
  x = min(x, y);
}

constexpr int N = 1E4 + 1;

int a[N][N];
int f[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  
  rep (i, 0, n) {
    rep(j, 0, m) {
      f[i][j] = 0x3f3f3f3f;
    }
  } 
  // memset(f, 0x3f, sizeof f);

  queue<pair<int, int> > q;

  rep(i, 1, n) {
    rep(j, 1, m) {
      cin >> a[i][j];
      if (!a[i][j]) {
        f[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    auto t = q.front(); q.pop();
    rep(i, 0, 3) {
      auto [nx, ny] = t;
      nx += dx[i];
      ny += dy[i];
      if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;;
      if (a[nx][ny] < a[nx - dx[i]][ny - dy[i]]) continue;
      if (f[nx][ny] != 0x3f3f3f3f) continue;
      chkmin(f[nx][ny], f[nx - dx[i]][ny - dy[i]] + 1);
      q.push(make_pair(nx, ny));
    }
  }

  rep(i, 1, n) {
    rep(j, 1, m) {
      if (f[i][j] == 0x3f3f3f3f) f[i][j] = -1;
      cout << f[i][j] << " \n"[j == m];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  //cin >> T;
  while (T--) solve();
  return 0;
}