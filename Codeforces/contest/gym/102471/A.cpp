#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  int n, m; cin >> n >> m;
  ll ans = 0;
  for(int i = 0; i <= n; i ++ ) {
    for(int j = 0; j <= m; j ++ ) {
      int l = min(i, n - i), r = min(j, m - j);
      ans += 1ll * (l) * (r) * 2;
      ans += l + r;
    }
  }
  cout << ans << "\n";

  return 0;
}