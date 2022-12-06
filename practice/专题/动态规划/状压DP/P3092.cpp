#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1e5 + 10, M = 1 << 16;

ll a[16];
ll s[N];
int f[M];

int main() {
  // freopen("P3092_3.in", "r", stdin);
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k; cin >> k >> n;
  ll sum = 0;
  for(int i = 0; i < k; i ++ ) {
    cin >> a[i]; sum += a[i];
  }
  for(int i = 1; i <= n; i ++ ) {
    cin >> s[i]; s[i] += s[i - 1];
  }
  if(sum < s[n]) {
    cout << "-1\n";
    return 0;
  }
  s[n + 1] = INT64_MAX;
  for(int i = 0; i < 1 << k; i ++ ) {
    for(int j = 0; j < k; j ++ ) if(not (i >> j & 1)) {
      if(f[i] >= n) {
        f[i ^ (1 << j)] = n;
      } else {
        int idx = upper_bound(s + 1, s + n + 2, s[f[i]] + a[j]) - s - 1;
        chkmax(f[i ^ (1 << j)], idx);
      }
    }
  }

  ll ans = 0;
  for(int i = 0; i < 1 << k; i ++ ) if(f[i] >= n) {
    ll ret = 0;
    for(int j = 0; j < k; j ++ ) if(not (i >> j & 1)) {
      ret += a[j];
    }
    chkmax(ans, ret);
  }
  cout << ans << "\n";

  return 0;
}