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

// int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void solve() {
  int n, m, k, t; cin >> n >> m >> k >> t;
  vector<vector<int> > g(n + 1, vector<int> (m + 1, -1));
  vector<int> height(m + 1);

  auto check = [&] (int x, int y) -> bool {
    int l = y, r = y;
    while (l - 1 >= 1 && g[x][l - 1] == g[x][y]) -- l;
    while (r + 1 <= m && g[x][r + 1] == g[x][y]) ++ r;
    if (r - l + 1 >= k) return true;

    l = x, r = x;

    while (l - 1 >= 1 && g[l - 1][y] == g[x][y]) -- l;
    while (r + 1 <= n && g[r + 1][y] == g[x][y]) ++ r;

    if (r - l + 1 >= k) return true;

    int lx = x, ly = y;
    while (lx - 1 >= 1 && ly - 1 >= 1 && g[lx - 1][ly - 1] == g[x][y]) {
      -- lx, -- ly;
    }
    int rx = x, ry = y;
    while (rx + 1 <= n && ry + 1 <= m && g[rx + 1][ry + 1] == g[x][y]) {
      ++ rx, ++ ry;
    }

    if (rx - lx + 1 >= k) return true;

    lx = x, ly = y;
    while (lx - 1 >= 1 && ly + 1 <= m && g[lx - 1][ly + 1] == g[x][y]) {
      -- lx, ++ ly;
    }
    rx = x, ry = y;
    while (rx + 1 <= n && ry - 1 >= 1 && g[rx + 1][ry - 1] == g[x][y]) {
      ++ rx, -- ry;
    }

    if (rx - lx + 1 >= k) return true;

    return false;

  };

  for (int i = 1; i <= t; i ++ ) {
    int pos; cin >> pos;
    height[pos] ++;
    g[height[pos]][pos] = (i & 1);
    if (check(height[pos], pos)) {
      return cout << i << "\n", void();
    }
  }

  cout << t << "\n";

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
