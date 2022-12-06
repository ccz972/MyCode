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
constexpr int N = 130;

ll a[N][N];

ll get(ll t, ll x, ll y) {
  memset(a, 0, sizeof a);
  // - (x + y) 是因为只有 (x + y) 步之后的才能到 x, y
  a[0][0] = max(t - (x + y) + 1, 0ll);
  // cout << a[0][0] << " ";
  for (int i = 0; i <= x; i ++ ) {
    for (int j = 0; j <= y; j ++ ) {
      a[i + 1][j] += a[i][j] / 2;
      a[i][j + 1] += a[i][j] - a[i][j] / 2;
    }
  }
  return a[x][y];
}

void solve() {
  ll t, x, y; cin >> t >> x >> y;
  // cout << get(t, x, y) << " :: " <<  get(t - 1, x, y) << "\n";
  if (get(t, x, y) - get(t - 1, x, y) > 0) cout << "YES\n";
  else cout << "NO\n";
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
