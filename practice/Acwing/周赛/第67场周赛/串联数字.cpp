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

constexpr int N = 2E5 + 10;

ll a[N], last[N][11];

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp[11];
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    last[i][0] = a[i] % k;
    for (int j = 1; j <= 10; j ++ ) {
      last[i][j] = (last[i][j - 1] * 10) % k;
    }
    int len = to_string(a[i]).size();
    mp[len][last[i][0]] ++;
  }
  ll ans = 0;

  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= 10; j ++ ) {
      auto p = (k - last[i][j]) % k;
      if (p < 0) p += k;
      if (mp[j].count(p))
        ans += mp[j][p];
    }
    int len = to_string(a[i]).size();
    if ((last[i][len] + last[i][0]) % k == 0) -- ans;
  }

  cout << ans << "\n";
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}