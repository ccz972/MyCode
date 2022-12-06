#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
clock_t start = clock();
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

const int N = 1E6 + 10;

int n, k, m;
int a[N], dp[N];
pair<int, int> p[N];
template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) { fenw.resize(n); }

  void modify(int x, T v) {
    while (x < n) {
      chkmax(fenw[x], v);
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v = 0;
    while (x >= 0) {
      chkmax(v, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

void solve() {
  cin >> n >> k;
  rep(i, 1, n) {
    cin >> a[i];
    if (a[i] <= i && i - a[i] <= k && a[i] <= n - k)
      p[m++] = make_pair(i - a[i], a[i]);
  }
  sort(p, p + m);
  fenwick<int> fen(n + 10);
  for (int i = 0; i < m; i++) {
    int now = fen.get(p[i].second - 1);
    fen.modify(p[i].second, now + 1);
  }
  cout << fen.get(n);
}

void solve2() {
  cin >> n >> k;
  vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    if (i > k) cnt += (i - a[i] == k);
  } 
  vector<vector<int> > dp(n + 1, vector<int> (k + 1, 0));
  int ans = 0;
  for (int i = 1; i <= n; i ++ ) {
    if (i > k) cnt -= (i - a[i] == k);
    for (int j = 0; j <= min(i, k); j ++ ) {
      if (j) dp[i][j] = dp[i - 1][j - 1];
      dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i] == i - j));
    }
    if (i >= k) {
      chkmax(ans, dp[i][k] + cnt);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve2();
#ifdef LOCAL
  clock_t ends = clock();
#endif
  return 0;
}
