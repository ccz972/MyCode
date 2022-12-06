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

ll ksm(ll a, ll b, ll p, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return ret;
}

constexpr int N = 1E6 + 10;
int n, p, a[N], b[N];

void solve() {
  cin >> n >> p;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i]; a[i] %= p;
  }
  for (int i = 1; i <= n; i ++ ) {
    cin >> b[i];
  }
  vector<int> c(p); bool flag = true;
  for (int i = 1; i <= n; i ++ ) {
    int x = (b[i] - a[i]) % p;
    if (x < 0) x += p;
    if (x) c[x] ++, flag = false;
  }
  if (flag) return cout << "0", void();
  n = c.size();
  int ans, inf = INT_MAX;
  for (int x = 1; x < p; x ++ ) {
    int q = ksm(x, p - 2, p);
    int res = 0;
    for (int i = 1; i < p; i ++ ) if (c[i]) {
      chkmax(res, (q * i) % p);
    }
    if (res < inf) {
      inf = res;
      ans = x;
    }
  }
  cout << ans;

  //(a + kx) = b
  //kx = b - a
  //k = (b - a) * x^{p-2}

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}