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
ll a[N], cost[N];
vector<int> son[N];
int deg[N];
bool st[N];




void solve8() {
  int n, m; cin >> n >> m;
  rep (i, 1, n) cin >> a[i];
  rep (i, 1, m) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
    deg[u] ++, deg[v] ++;
  }

  queue<int> q;

  for (int i = 1; i <= n; i ++ ) if (deg[i] == 1) {
    st[i] = true;
    q.push(i);
  }

  ll ans = 0;

  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v: son[u]) {
      if (!st[v]) chkmax(ans, a[v]);
      if (-- deg[v] == 1 && !st[v]) {
        q.push(v);
        chkmax(ans, a[v]);
        st[v] = true;
      }
    }
  }

  cout << ans << "\n";




}

void solve() {
  int n, m; cin >> n >> m;
  rep (i, 1, n) cin >> a[i];
  rep (i, 1, m) {
    int u, v; cin >> u >> v;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
    cost[u] += a[v];
    cost[v] += a[u];
  }

  multiset<pair<ll, int> > s;

  rep(i, 1, n) s.insert(make_pair(cost[i], i));

  ll ans = 0;

  while (!s.empty()) {
    auto t = s.begin();
    auto val = t->first;
    auto u = t->second;
    chkmax(ans, val); 
    st[u] = true;
    for (auto v: son[u]) if (!st[v]) {
      auto idx = s.lower_bound(make_pair(cost[v], v));
      auto VAL = idx->first;
      VAL -= a[u]; cost[v] -= a[u];
      s.erase(idx);
      s.insert(make_pair(VAL, v));
    }
    s.erase(t);
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