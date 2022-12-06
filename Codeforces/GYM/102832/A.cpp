#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; cin >> n;
  vector<int> a{1, 6, 28, 88, 198, 328, 648};
  vector<int> b{8, 18, 28, 58, 128, 198, 388};
  int sz = a.size();
  ll ans = 0;
  for (int i = 0; i < 1 << sz; i ++ ) {
    ll ret = 0;
    auto now = n;
    for (int j = 0; j < sz; j ++ ) if (i >> j & 1) {
      if (now >= a[j]) {
        now -= a[j];
        ret += a[j] * 10;
        ret += b[j];
      }
    }
    ret += now * 10;
    ans = max(ans, ret);
  }
  cout << ans << "\n";
  // long long ans = 0;
  // for (int i = sz - 1; i >= 0; i -- ) {
  //   if (n >= a[i]) {
  //     ans += a[i] * 10;
  //     ans += b[i];
  //     n -= a[i];
  //   }
  // } 
  // ans += n * 10;
  // cout << ans << "\n";
  return 0;
}