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


void solve() {
  int n, x, y; cin >> n >> x >> y;
  string s, t; cin >> s >> t;
  s = " " + s;
  t = " " + t;
  vector<int> idx;
  for (int i = 1; i <= n; i ++ ) if (s[i] != t[i]) {
    idx.emplace_back(i);
  }
  if ((int)idx.size() & 1) {
    cout << "-1\n";
    return ;
  }
  int m = idx.size();
  if (m == 2) {
    if (idx[0] + 1 == idx[1]) {
      cout << min(x, 2 * y) << "\n";
    } else {
      cout << y << "\n";
    }
  } else {
    cout << 1ll * y * (m / 2) << "\n";
  }
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
