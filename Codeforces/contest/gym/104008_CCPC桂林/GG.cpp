#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define FUCK debug("fuck")
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

  ll ans = 0;
  
  vector h(n + 1, vector<pair<ll, int> > (3));
  //h[i][j] 表示 以 i 为根的子树的最长链 or 次长链 的 权值和 和 编号
  //需要换根

  vector<ll> f(n + 1); //子树的最长带权直径 两种的最大值

  vector<ll> dp(n + 1);
  //表示除了点 u 的子树中的点所构成的最长带权直径，那么考虑这个直径的构成方式，两种取个最大值。
  vector g(n + 1, vector<pair<ll, int> > (2));
  vector F(n + 1, vector<pair<ll, int> > (2));
  

  /**
   * 以 1 为根的子树中，u 的子树中的最长带权直径长度
   * 并且此时的直径是由 不包含 u 的路径(即由 u 的子树中的点)构成。
   * g[u][0] 表示最长直径和这个值所在的儿子的编号， g[u][1] 为次长。
  */

  function<void(int, int)> dfs = [&] (int u, int fa) {
    for (int &v: son[u]) if (v != fa) {

      dfs (v, u);

      if (h[v][0].first >= h[u][0].first) {
        h[u][2] = h[u][1];
        h[u][1] = h[u][0];
        h[u][0] = {h[v][0].first, v};
      } else if (h[v][0].first >= h[u][1].first) {
        h[u][2] = h[u][1];
        h[u][1] = {h[v][0].first, v};
      } else if (h[v][0].first >= h[u][2].first) {
        h[u][2] = {h[v][0].first, v};
      } 

      ll mx = max(f[v], g[v][0].first);
      if (f[v] >= F[u][0].first) {
        F[u][1] = F[u][0];
        F[u][0] = {f[v], v};
      } else if (f[v] >= F[u][1].first) {
        F[u][1] = {f[v], v};
      }
      if (mx >= g[u][0].first) {
        g[u][1] = g[u][0];
        g[u][0] = {mx, v};
      } else if (mx >= g[u][1].first) {
        g[u][1] = {mx, v};
      }

    }

    chkmax(f[u], w[u] + h[u][0].first + h[u][1].first);

    h[u][0].first += w[u];
    h[u][1].first += w[u];
    h[u][2].first += w[u];

    chkmax(ans, g[u][0].first + g[u][1].first);
  };
  
  dfs(1, 0);

  function<void(int, int)> DFS = [&] (int u, int fa) {
    
    for (int &v: son[u]) if (v != fa) {
      ll now = h[u][0].second == v ? h[u][1].first : h[u][0].first;
      now += w[v];
      if (now >= h[v][0].first) {
        h[v][2] = h[v][1];
        h[v][1] = h[v][0];
        h[v][0] = {now, u};
      } else if (now >= h[v][1].first) {
        h[v][2] = h[v][1];
        h[v][1] = {now, u};
      } else if (now >= h[v][2].first) {
        h[v][2] = {now, u};
      }

      DFS(v, u);
    }
  };

  DFS(1, 0);

  function<void(int, int)> dfs1 = [&] (int u, int fa) {
    if (son[u].empty()) return ;
    vector<pair<ll, pair<int, int> > > a;
    /////////////////////////// 选当前点 u 的四条链，需要保证链不是从 u 转移过来的
    for (int &v: son[u]) {
      if (h[v][0].second != u) {
        a.push_back(make_pair(h[v][0].first, make_pair(h[v][0].second, v)));
      } else {
        a.push_back(make_pair(h[v][1].first, make_pair(h[v][1].second, v)));
      }
      // if (v != fa) chkmax(dp[v], dp[u]);
    }
    
    sort(all(a), greater<pair<ll, pair<int, int> > >());

    int m = min(SZ(a), 4); ll now = 0;
    Rep(i, 0, m) now += a[i].first;

    chkmax(ans, now);
    /////////////////////////// 选当前点的四条链


    ///////////////////////////选当前点 和 三条链
    chkmin(m, 3);
    now = w[u];
    Rep(i, 0, m) {
      now += a[i].first;
    } 
    chkmax(ans, now);
    
    ///////////////////////////选当前点 和 三条链
    //需要知道以 u 为根的树中，每个儿子的子树中的最大直径，取前二大
    
    // g[u][0], g[u][1],   all(f[v])  以及从父亲那边转移过来的 取前2大
    //父亲那边转移过来的假设是dp[u]

    if (fa) {
      ll now = 0; int cnt = 0;
      Rep(i, 0, 3) if (cnt < 2 && h[u][i].second != fa) {
        now += h[u][i].first - w[u];
        ++ cnt;
      }
      now += w[u];

      ll Now = 0; int Cnt = 0;
      Rep(i, 0, 3) if (Cnt < 2 && h[fa][i].second != u) {
        Now += h[fa][i].first - w[fa];
        ++ Cnt;
      }
      Now += w[fa];
      chkmax(ans, Now + now);
    }



    vector<ll> tmp{g[u][0].first, g[u][1].first};

    if (fa) {
      auto [val0, idx0] = h[fa][0];
      auto [val1, idx1] = h[fa][1];
      auto [val2, idx2] = h[fa][2];
      set<int> s{idx0, idx1, idx2}; 
      vector<ll> fuck;
      auto flag = s.count(u);
      if (!flag) {
        tmp.push_back(val0); tmp.push_back(val1);
        fuck.push_back(val0); fuck.push_back(val1);
      } else {
        Rep(i, 0, 3) {
          auto [val, idx] = h[fa][i];
          if (idx != u) {
            tmp.push_back(val);
            fuck.push_back(val);
          }
        }
      }
      sort(all(fuck), greater<ll>());
      //父亲的儿子的子树中的最大直径
      dp[u] = max(dp[fa], g[fa][0].second == u ? g[fa][1].first : g[fa][0].first);
      //父亲和父亲的另外两个儿子组成的链
      chkmax(dp[u], fuck[0] + fuck[1] - (fuck[0] != 0 && fuck[1] != 0) * w[fa]);

      ll mx = F[u][0].first + F[u][1].first;
      chkmax(mx, max(g[u][0].first, F[u][0].first) + dp[u]);
      if (g[u][0].second != F[u][0].second) {
        chkmax(mx, g[u][0].first + F[u][0].first);
      } else {
        chkmax(mx, g[u][0].first + F[u][1].first);
        chkmax(mx, g[u][1].first + F[u][0].first);
      }
      chkmax(ans,  mx);

    }

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