#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = n; i >= 0 && k > 0; i -- ) {
    if (!a[i]) break;
    if (a[i] == a[i - 1]) continue;
    auto p = a[i] - a[i - 1];
    int cnt = n - i + 1;
    long long maxtimes = p * cnt;
    if (maxtimes >= k) {
      auto x = k / cnt, y = k % cnt;
      ans += (a[i] + a[i] - x + 1) * x / 2 * cnt;
      ans += (a[i] - x) * y;
      break;
    } else {
      ans += (a[i] + a[i - 1] + 1) * p / 2 * cnt;
      k -= maxtimes;
    }
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