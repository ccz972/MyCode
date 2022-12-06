#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

void solve() {
  int n; cin >> n;
  vector<vector<pair<int, int> > > son(n + 1);
  vector<stack<int> > stk(n + 1);
  vector<int> dp(2 * n + 2);
  Rep(i, 1, n) {int u, v, w; cin >> u >> v >> w; son[u].eb(v, w); son[v].eb(u, w); }
  rep(i, 1, n) stk[i].push(n + i), dp[n + i] = n;
  vector<int> sz(n + 1);
  ll ans = 0;
  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    sz[u] = 1;
    for (auto &[v, w]: son[u]) if (v != fa) {
      stk[w].push(v);
      dfs1(v, u);
      sz[u] += sz[v];
      stk[w].pop();
      dp[stk[w].top()] -= sz[v];
    }
    dp[u] += sz[u];
  };
  function<void(int, int)> dfs2 = [&] (int u, int fa) {
    sz[u] = 1;
    for (auto &[v, w]: son[u]) if (v != fa) {
      stk[w].push(v);
      dfs2(v, u);
      stk[w].pop();
      // debug(v, stk[w].top(), dp[v], dp[stk[w].top()]);
      ans += 1ll * dp[v] * dp[stk[w].top()];
    }
  };
  dfs1(1, 0); dfs2(1, 0);
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}