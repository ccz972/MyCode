#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif
#define int long long
// template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
// template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

bool solve2() {
  ll s; cin >> s;
  vector<ll> a(7); for(int i = 1; i <= 6; i ++ ) cin >> a[i];
  s -= a[6]; if(s < 0) return false;
  int cnt1 = 0, cnt2 = 0;
  s -= a[5]; if(s < 0) return false; cnt1 += a[5] * 11;
  s -= a[4]; if(s < 0) return false; cnt2 += a[4] * 5;
  s -= (a[3] + 3) / 4; if(s < 0) return false;
  int last = ((a[3] % 4 > 0) ? 4 - a[3] % 4 : 0) ;
  if(last == 1) { cnt1 += 5, cnt2 += 1; } 
  else if(last == 2) { cnt1 += 6, cnt2 += 3; } 
  else if(last == 3) { cnt1 += 7, cnt2 += 5; }
  if(a[2] <= cnt2) { cnt2 -= a[2]; a[2] = 0; cnt1 += cnt2 * 4; } 
  else { a[2] -= cnt2; cnt2 = 0; s -= (a[2] + 8) / 9; if(s < 0) return false; cnt1 += ((a[2] % 9 > 0) ? (9 - (a[2] % 9)) * 4 : 0);}
  s = s * 36 + cnt1 - a[1]; if(s < 0) return false;
  return true;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve2() ? "Yes" : "No") << "\n";
  }
  return 0;
}