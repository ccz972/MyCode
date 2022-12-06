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

constexpr int N = 1010;


void solve() {
  int n, m; cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i ++ ) {
    cin >> s[i];
  }

  vector<int> cnt(3, 0);
  auto check = [&] (int x, int y, char c, int ret = 0) -> int {
    int now = y; 
    while (now + 1 < m && s[x][now + 1] == c && now - y + 1 <= 6) ++ now;
    if (now - y + 1 >= 5) ++ ret;
    now = x;
    while (now + 1 < n && s[now + 1][y] == c && now - x + 1 <= 6) ++ now;
    if (now - x + 1 >= 5) ++ ret;
    int l = x, r = y;
    while (l + 1 < n && r + 1 < m && s[l + 1][r + 1] == c && l - x + 1 <= 6) {
      ++ l, ++ r;
    }
    if (l - x + 1 >= 5) ++ ret;
    l = x, r = y;
    while (l - 1 >= 0 && r + 1 < m && s[l - 1][r + 1] == c && x - l + 1 <= 6) {
      -- l, ++ r;
    }
    if (x - l + 1 >= 5) ++ ret;
    return ret;
  };

  for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < m; j ++ ) if (s[i][j] != '0') {
      cnt[s[i][j] - '0'] += check(i, j, s[i][j]);
      // if (s[i][j] == '2' && check(i, j, s[i][j])) {
      //   debug(i, j, check(i, j, s[i][j]));
      // }
    }
  }

  cout << cnt[1] << " " << cnt[2];

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
