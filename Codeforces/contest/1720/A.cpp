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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x = a * d, y = b * c;
  if (x == y) {
    cout << "0\n";
  } else {
    if (x > y) swap(x, y);
    if (x == 0 || y % x == 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
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
