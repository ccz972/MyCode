#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 1E5 + 10;
constexpr int M = 2E5 + 10;

int mp[N];
ll a[N], s[M];

void solve() {
  int n, q; cin >> n >> q;
  ll x; cin >> x;
  for (int i = 1; i <= n; i ++ ) cin >> a[i];
  memset(mp, -1, sizeof mp);
  for (int i = 1; i <= n << 1; i ++ ) s[i] = s[i - 1] + a[i];

  int base = x / s[n];
  x %= s[n];
  vector<int> f;
  
  int i = 0, cc = 0, t1, t2;

  while (true) {
    int j = lower_bound(s, s + 2 * n + 1, s[i] + x) - s;
    if (mp[i] >= 0) {
      t1 = mp[i];
      t2 = (int)f.size() - t1;
      break;
    } else {
      mp[i] = cc ++;
      f.emplace_back(j - i + base);
    }
    i = j % n;
  }

  while (q -- ) {
    ll k; cin >> k;
    if (k > t1) {
      cout << f[(k - t1 - 1) % t2 + t1] << "\n";
    } else {
      cout << f[k - 1] << "\n";
    }
  }

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
