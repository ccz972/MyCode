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

constexpr int N = 5110;
constexpr ll INF = 1E18;

ll f[N];
int a[N];
void solve() {
  int n, m; ll x, y; cin >> n >> x >> y;
  string s, t; cin >> s >> t; m = 0;
  for (int i = 0; i < n; i ++ ) if (s[i] != t[i]) {
    a[++ m] = i + 1;
  }

  if (m == 0) return cout << "0\n", void();
  if (m & 1) return cout << "-1\n", void();

  if (x >= y) {
    if (m == 2 && a[1] + 1 == a[2]) return cout << min(2 * y, x) << "\n", void();
    else return cout << y * m / 2 << "\n", void();
  }
  // x < y 能相邻就相邻
  for (int i = 2; i <= m; i ++ ) {
   if (i & 1) {
      f[i] = min(f[i - 2] + min(x * (a[i] - a[i - 1]), y), f[i - 1]);
    } else {
      f[i] = min(f[i - 2] + min(x * (a[i] - a[i - 1]), y), f[i - 1] + y);
    }
  }
  // for (int i = 1; i <= m; i ++ ) {
  //   cout << f[i] << " \n"[i == m];
  // }
  cout << f[m] << "\n";
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
