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
  vector<ll> s(n);
  for (ll &x: s) cin >> x;
  sort(s.begin(), s.end());
  reverse(s.begin(), s.end());
  
  ll ans = -1;
  ll ji = -1, ou = -1;
  for (int i = 0; i < n; i ++ ) {
    if (s[i] & 1) {
      if (ji == -1) ji = s[i];
      else chkmax(ans, ji + s[i]);
    } else {
      if (ou == -1) ou = s[i];
      else chkmax(ans, ou + s[i]);
    }
  }
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}