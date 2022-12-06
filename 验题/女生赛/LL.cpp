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
constexpr int N = 1E5 + 10;

vector<int> son[N];
int n, k; 
int col[N], ans[N], depth[N], sz[N], hson[N], dfn[N], cnt[N], idx[N];
int nc;


void dfs1(int u, int fa) {
  sz[u] = 1;
  depth[u] = depth[fa] + 1;
  dfn[++ nc] = u;
  idx[dfn[u]] = u;
  for (int &v : son[u]) if (v != fa) {
    dfs1(v, u);
    sz[u] += sz[v];
    if (!hson[u] || sz[v] > sz[hson[u]] ) {
      hson[u] = v;
    }
  }
}

class fenwick {
public: 
  vector<int> fenw;
  int n;

  fenwick(int _n): n (_n)  {
    fenw.resize(n);
  }
  
  void modify(int x, int v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  int get(int x) {
    int v = 0;
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }

  int get(int l, int r) {
    return get(r) - get(l - 1);
  }

} ;

void dfs(int l, int r) {
  if (l == r) {
    ans[l] = 1;
    return ;
  } 

  int mid = (l + r) / 2;
  dfs(l, mid); dfs(mid + 1, r);
  fenwick fen(n + 10);
  for (int i = l, j = l - 1; i <= mid; i ++ ) {
    chkmax(j, i - 1);
    if (i + sz[idx[i]] - 1 <= mid) continue;
    while (j + 1 <= i + sz[idx[i]] - 1) {
      ++ j;
      cnt[col[idx[j]]] ++;
      if (cnt[col[idx[j]]] == 1) {
        fen.modify(col[idx[j]], 1);
      }
    }

    ans[idx[i]] = fen.get(1, n + 1);
    
    cnt[col[idx[i]]] --;

    if (cnt[col[idx[i]]] == 1) {
      fen.modify(col[idx[i]], -1);
    }
  }

}

void solve() {
  cin >> n >> k;
  Rep(i, 1, n) {
    int u, v, w; cin >> u >> v >> w;
    son[u].emplace_back(v);
    son[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs(1, n);
  int q; cin >> q;
  while (q -- ) {
    int x; cin >> x;
    cout << ans[x] << "\n";
  }


}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}