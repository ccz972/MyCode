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

constexpr int N = 2E5 + 10, M = 4E5 + 10;

ll w[M];
int mp[N];

void solve() {
  int n, q, x; cin >> n >> q >> x;
  
  rep (i, 1, n) {
    cin >> w[i]; w[i + n] = w[i];
    mp[i - 1] = -1;
  }
  for (int i = 1; i <= 2 * n; i ++ ) {
    w[i] += w[i - 1];
  }

  int i = 0, c1, c2;

  ll base = x / w[n] * n;
  x %= w[n];
  //0 1 3 5 6
  //0 1 2 3 4 5 6 1 2
  vector<ll> ans;
  while (true) {
    int j = lower_bound(w, w + 2 * n + 1, w[i] + x) - w;
    if (mp[i] != -1) {
      c1 = mp[i];
      c2 = (int)ans.size() - c1;
      break;
    } else {
      mp[i] = ans.size();
      ans.emplace_back(base + j - i);
    }
    i = j % n;
  }

  while (q -- ) {
    ll k; cin >> k;
    if (k <= c1) {
      cout << ans[k - 1] << "\n";
    } else {
      cout << ans[c1 + (k - c1 - 1) % c2] << "\n";
    }
  }



}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
