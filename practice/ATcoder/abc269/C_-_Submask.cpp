#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++i)
#define dec(i, a, b) for (int i(b); i >= a; --i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

void solve() {
  ll x; cin >> x;
  int px = __builtin_popcountll(x);
  vector<bool> vis(100);
  vector<int> now;
  for (int i = 0; i < 61; i ++ ) if (x >> i & 1) {
    vis[i] = true;
    now.push_back(i);
  }
  vector<ll> ans;
  for (int i = 0; i < 1 << px; i ++ ) {
    vector<int> pp;
    for (int j = 0; j < px; j ++ ) if (i >> j & 1) {
      pp.push_back(now[j]);
    }
    ll Now = 0;
    for (int x: pp) Now |= 1ll << x;
    ans.emplace_back(Now);
  }
  sort(ans.begin(), ans.end());
  for (auto &x: ans) cout << x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
