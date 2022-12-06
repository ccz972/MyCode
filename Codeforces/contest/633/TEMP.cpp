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

int n, m;
ll a[N], s[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  ll ans = INT64_MIN;
  ll now = 0;
  for (int i = 1; i <= m; i ++ ) {
    now += a[i] * i;
  }
  ans = now;
  for (int i = m + 1; i <= n; i ++ ) {
    now -= a[i - m];
    now -= s[i - 1] - s[i - m];
    now += a[i] * m;
    chkmax(ans, now);
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