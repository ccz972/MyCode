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
  int n; cin >> n;
  vector<array<ll, 2> > a(n);
  ll mxx = INT_MIN, mxy = INT_MIN, mix = INT_MAX, miy = INT_MAX;
  for(auto &[x, y]: a) {
    cin >> x >> y;
    if(x > 0) chkmax(mxx, x);
    if(x < 0) chkmin(mix, x);
    if(y > 0) chkmax(mxy, y);
    if(y < 0) chkmin(miy, y);
  }
  ll ans = 0;
  if(mxx != INT_MIN) ans += mxx * 2;
  if(mxy != INT_MIN) ans += mxy * 2;
  if(mix != INT_MAX) ans -= mix * 2;
  if(miy != INT_MAX) ans -= miy * 2;

  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}