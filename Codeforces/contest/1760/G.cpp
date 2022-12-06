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
constexpr ll INFF = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 1E5 + 10;

struct Trie {
  int c[N * 32][2], tot, v[N * 31];
  void init() {
    while (tot) {
      v[tot] = 0;
      memset(c[tot], 0, sizeof(c[tot]));
      --tot;
    }
    memset(c[0], 0, sizeof(c[0]));
    v[0] = 0;
  }
  void insert(int x) {
    int now = 0;
    for (int i = 31; i >= 0; i -- ) {
      int p = x >> i & 1;
      if (!c[now][p]) c[now][p] = ++ tot;
      now = c[now][p];
    }
    v[now] = 1;
  }

  bool query(int x) {
    int now = 0;
    for (int i = 31; i >= 0; i -- ) {
      int p = x >> i & 1;
      if (!c[now][p]) return false;
      now = c[now][p];
    }
    return v[now];
  }
} A;


void solve() {
  int n, a, b; cin >> n >> a >> b;
  vector<vector<pair<int, int> > > son(n + 1);
  for (int i = 1; i < n; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    son[u].emplace_back(v, w); son[v].emplace_back(u, w);
  }

  vector<int> val(n + 1), father(n + 1);

  function<void(int, int)> dfs = [&] (int u, int fa) {
    for (auto &[v, w] : son[u]) if (v != fa) {
      father[v] = u;
      val[v] = val[u] ^ w;
      dfs(v, u);
    }
  };

  dfs(b, 0);

  int now = a;
  
  while (father[now] != b) {
    now = father[now];
  }
  
  function<void(int, int)> DFS = [&] (int u, int fa) {
    A.insert(val[u]); 
    for (auto &[v, w] : son[u]) if (v != fa) {
      DFS(v, u);
    }
  };

  A.init();
  DFS(now, father[now]);

  int w = val[a] ^ val[b];

  if (!w) return cout << "YES\n", void();
  
  for (int i = 1; i <= n; i ++ ) if (i != b) {
    // debug(i, val[i] ^ w);
    if (A.query(val[i] ^ w)) return cout << "YES\n", void();
    // A.insert(val[i]);
    // debug(val[i]);
  }

  cout << "NO\n";


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}