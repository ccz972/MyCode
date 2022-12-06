#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, x; cin >> n >> x;
  vector<int> a(n); for(int &x: a) cin >> x;
  int l = a[0] - x;
  int r = a[0] + x;
  int ans = 0;
  for(int i = 1; i < n; i ++ ) {
    int L = a[i] - x, R = a[i] + x;
    if(L > r || l > R) {
      l = L, r = R;
      ++ ans;
    } else {
      chkmax(l, L);
      chkmin(r, R);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}