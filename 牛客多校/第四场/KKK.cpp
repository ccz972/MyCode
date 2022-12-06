#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n; cin >> n;
  if(n == 1) {
    cout << "0\n";
    return ;
  }
  int ans = 0;

  auto chk = [&] (ll l, ll r, ll nxt) {
    if(r - l >= n) {
      return true;
    }
    l %= n, r %= n;
    if(l < r) {
      if(l > nxt) return false;
      if(r < nxt) return false;
    } else {
      if(nxt < l && nxt > r) return false;
    }

    return true;

  };

  for(int i = 0; i < n; i ++ ) {
    int nxt = (i + 1) % n;
    ll l = i * 10, r = i * 10 + 9;
    for(int j = 1; j < n; j ++ ) {
      if(chk(l, r, nxt)) {
        ans += j;
        break;
      }
      l *= 10;
      r = r * 10 + 9;
    }
  }
  cout << ans << "\n";


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
