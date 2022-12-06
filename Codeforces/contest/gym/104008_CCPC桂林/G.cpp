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
  vector<ll> w(n + 1);
  rep(i, 1, n) cin >> w[i];
  vector<vector<int>> son(n + 1);
  for (int i = 1; i < n; i++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v), son[v].push_back(u);
  } 

  vector<vector<pair<ll, ll> > >mx(n + 1, vector<pair<ll, ll> > (2));

  function<void(int, int)> dfs = [&] (int u, int fa) {
    mx[u][0].first = mx[u][1].first = w[u];
    for (int &v: son[u]) if (v != fa) {
      dfs(v, u);
      auto [val, i] = mx[v][0]; //最大值
      if (val + w[u] >= mx[u][0].first) {
        mx[u][1] = mx[u][0];
        mx[u][0] = {val + w[u], v};
      } else if (val + w[u] >= mx[u][1].first) {
        mx[u][1] = {val + w[u], v};
      }
    }
    
    
  };

  dfs(1, 0);

  function<void(int, int)> DFS = [&] (int u, int fa) {
    for (int &v: son[u]) if (v != fa) {
      auto [val, i] = mx[u][0];
      if (mx[u][0].second == v) {
        val = mx[u][1].first;
        i = mx[u][1].second;
      }
      if (val + w[v] >= mx[v][0].first) {
        mx[v][1] = mx[v][0];
        mx[v][0] = {val + w[v], u};
      } else if (val + w[v] >= mx[v][1].first) {
        mx[v][0] = {val + w[v], u};
      }
      DFS(v, u);
    }
  };

  DFS(1, 0);

  vector<array<ll, 2> > f(n + 1);

  ll ans = 0;

  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    int cnt = SZ(son[u]);
    if (cnt == 0) return ;
    if (cnt == 1) {
      // f[u][0] = mx[son[u].front()][0].first + w[u];
      auto [val1, i1] = mx[son[u][0]][0];
      auto [val2, i2] = mx[son[u][0]][1];
      if (i1 == u) {
        f[u][0] = val2 + w[u];
      } else {
        f[u][0] = val1 + w[u];
      }
    } else if (cnt == 2) {
      // f[u][0] = mx[son[u][0]][0].first + w[u] + mx[son[u][1]][0].first;
      auto [val1, i1] = mx[son[u][0]][0];
      auto [val2, i2] = mx[son[u][0]][1];
      if (i1 == u) {
        f[u][0] = val2 + w[u];
      } else {
        f[u][0] = val1 + w[u];
      }

      auto [Val1, I1] = mx[son[u][1]][0];
      auto [Val2, I2] = mx[son[u][1]][1];
      if (I1 == u) {
        f[u][0] += Val2;
      } else {
        f[u][0] += Val1;
      }
    } else if (cnt == 3) {
      for (int &v: son[u]) {
        auto [val1, i1] = mx[v][0];
        auto [val2, i2] = mx[v][1];
        if (i1 == u) {
          f[u][0] += val2;
          // a.pb(val2);
        } else {
          f[u][0] += val1;
          // a.pb(val1);
        }
      }
      f[u][0] += w[u];

    } else {
      vector<ll> a;

      for (int &v: son[u]) {
        auto [val1, i1] = mx[v][0];
        auto [val2, i2] = mx[v][1];
        if (i1 == u) {
          // f[u][0] += val2;
          a.pb(val2);
        } else {
          // f[u][0] += val1;
          a.pb(val1);
        }
      }

      sort(all(a), greater<int>());
      // debug(u, a);
      f[u][0] += a[0] + a[1] + a[2] + w[u];
      f[u][1] += a[0] + a[1] + a[2] + a[3];
    }
    chkmax(ans, f[u][0]);
    chkmax(ans, f[u][1]);
    for (int &v: son[u]) if (v != fa) {
      dfs1(v, u);
    }
  };

  dfs1(1, 0);



  


  cout << ans << "\n";

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}