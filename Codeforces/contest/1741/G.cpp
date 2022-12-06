#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
void solve();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T --) solve();
  return 0;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int> > son(n + 1);
  for (int i = 1; i <= m; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v); son[v].emplace_back(u);
  }
  int f; cin >> f;
  vector<int> a(f + 1); // for (int &x: a) cin >> x; // a[i]表示 i + 1 的家
  for (int i = 1; i <= f; i ++ ) cin >> a[i];
  int k; cin >> k;
  vector<int> b(k); for (int &x: b) cin >> x; // b 数组中的数字表示 这些人没车
  queue<int> q;
  q.push(1);
  set<int> s[n + 1];
  for (int i = 1; i <= n; i ++ ) s[i].insert(0);
  vector<int> dist(n + 1, 1E9);
  dist[1] = 0;
  while (q.size()) {
    auto t = q.front(); q.pop();
    // auto [u, state] = t;
    auto u = t;
    for (auto &v: son[u]) if (dist[v] >= dist[u] + 1) {
      int have = 0;
      for (int i = 0; i < k; i ++ ) if (a[b[i]] == v) {
        // have.push_back(i);
        have |= 1 << i;
      }
      for (int x: s[u]) {
        s[v].insert(x | have);
      }
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  vector<int> dp(1 << k);
  dp[0] = true;
  for (int i = 1; i <= f; i ++ ) if (!count(b.begin(), b.end(), i)) {
    int u = a[i];
    auto ndp = dp;
    for (int j = 0; j < 1 << k; j ++ ) if (ndp[j]) {
      for (int p: s[u]) {
        dp[j | p] = 1;
      }
    }
  }  
  int mx = 0;
  for (int i = 0; i < 1 << k; i ++ )  if (dp[i]) {
    int num = __builtin_popcount(i);
    chkmax(mx, num);
  }
  cout << k - mx << "\n";
}