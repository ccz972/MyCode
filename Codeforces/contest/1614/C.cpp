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
constexpr int P = 1E9 + 7;
void solve();
ll ksm(ll a, ll b, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % P;
    b >>= 1;
    a = a * a % P;
  }
  return ret;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T --) {
    solve();
  }
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}


void solve() {
  int n, k; cin >> n >> k;
  int ret = 0;
  while (k -- ) {
    int x; cin >> x >> x >> x;
    ret |= x;
  }
  ll ans = ksm(2, n - 1);
  ans = (ans * ret) % P;
  cout << ans << "\n";

}