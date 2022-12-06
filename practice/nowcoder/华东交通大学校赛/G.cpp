// lqmm
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

constexpr int N = 2E5 + 10;
struct Trie {
  int c[N * 32][2], tot, v[N * 32], w;
  void init(int m) {
    w = m;
    while (tot) {
      v[tot] = 0;
      c[tot][0] = c[tot][1] = 0;
      --tot;
    }
    c[0][0] = c[0][1] = 0;
    v[0] = 0;
  }

  void insert(int x) {
    int now = 0;
    for (int i = 31; i >= 0; i -- ) {
      int to = x >> i & 1;
      if (!c[now][to]) c[now][to] = ++ tot;
      now = c[now][to];
      v[now] ++;
    }
    // v[now] ++;
    // debug(x, "YES");
  }

  int query(int x) {
    int now = 0, ret = 0;
    for (int i = 31; i >= 0; i -- ) {
      int to = x >> i & 1;
      if (not (w >> i & 1)) {
        if (!c[now][to]) return ret;
        now = c[now][to];
      } else {
        if (c[now][to]) {
          ret += v[c[now][to]];
          // debug(x, ret, i);
        }
        if (!c[now][to ^ 1]) return ret;
        now = c[now][to ^ 1];
      }
    }
    // ret += v[now];
    // debug(x);
    return ret;
  }

  // void dfs(int u) {
  //   for (int i = 0; i < 32; i ++ ) if (c[u][i]) {
  //     dfs(c[u][i]);
  //     v[u] += v[c[u][i]];
  //   }
  // }

} A;


void solve() {
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int> > > son(n + 1);
  A.init(m);
  for (int i = 1; i < n; i++ ) {
    int u, v, w; cin >> u >> v >> w; // u --, v --;
    son[u].push_back(make_pair(v, w)), son[v].push_back(make_pair(u, w));
  }

  
  vector<int> sz(n + 1, 1), depth(n + 1), hson(n + 1), val(n + 1);

  function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto& [v, w] : son[u]) if(v != fa) {
      val[v] = val[u] ^ w;
      dfs(v, u);
    }
  };

  dfs(1, 0);

  ll ans = 0;

  rep(i, 1, n) {
    ans += A.query(val[i]);
    A.insert(val[i]);
  }

  ans = ans * 2 + n;

  cout << ans << "\n";


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}