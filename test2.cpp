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

constexpr int N = 1E5 + 10;

ll n, k;
ll a[N];
set<int> s[N];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    s[a[i]].insert(i);
    if ((int)s[a[i]].size() > 2) {
      s[a[i]].erase(s[a[i]].begin());
    }
  }
  int m = __lg(n + 1) + 1;
  ll ans = -1E18;
  for (int i = 0; i < 1 << m; i ++ ) {
    for (int j = 0; j < m; j ++ ) {
      if (i >> j & 1) {
        for (int x: s[i ^ (1 << j)]) {
          
        }
      }
    }
    if ((int)s[i].size() == 2) {
      chkmax(ans, *s[i].begin() * *s[i].rbegin() - k * i);
    }
  }
  cout << ans << "\n";
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
