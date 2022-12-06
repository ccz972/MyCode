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

constexpr int N = 1E5 + 10;

int a[N], cnt[N];

void solve() {
  int n, m; cin >> n >> m;
  ll ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  // int now = 1; cnt[a[1]] ++;
  int now = 0;
  for(int i = 1, j = 0; i <= n; i ++ ) {
    while(now < m && j < n) {
      ++ j;
      if(!cnt[a[j]]) ++ now;
      cnt[a[j]] ++;
    }
    //ans += 1ll * i * (n - j + 1);
    if(now == m)
      ans += (n - j + 1);
    cnt[a[i]] --;
    if(!cnt[a[i]]) -- now;
    // cout << ans << "\n";
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; ///cin >> T;
  while(T -- ) solve();
  return 0;
}