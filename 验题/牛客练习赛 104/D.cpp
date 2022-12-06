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

struct DSU {
  vector<int> f, siz, rank;
  int cnt; //统计还剩多少个连通块
  DSU(int n) : cnt(n), f(n), rank(n, 0), siz(n, 1) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return -1;
    else -- cnt;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; //按秩合并 and 路径压缩 
 

constexpr int N = 1E5 + 10;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int> > son[N];

struct node {
  int ver; ll dist;
  bool operator < (const node &T) const {
    return dist > T.dist;
  }
};

void solve() {
  int n, m, s, t, k;
  cin >> n >> m >> s >> t >> k;
  // 代表N星球中的城市数量、道路数量、贝贝所在城市、安全点对应的城市、N药水的数量。
  DSU d(n + 1);
  int l = 0, r = 0;
  for (int i = 0; i < m; i ++ ) {
    int u, v, w; cin >> u >> v >> w; chkmax(r, w);
    son[u].emplace_back(v, w);
    son[v].emplace_back(u, w);
    d.merge(u, v);
  }

  if (s == t) return cout << "0\n", void();

  if (!d.same(s, t)) return cout << "I really need TS1's time machine again!\n", void();

  auto chk = [&] (int x) -> bool {
    priority_queue<node> q;
    vector<ll> dist(n + 1, INF);
    vector<bool> st(n + 1, false);
    // int K = k;
    dist[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
      auto [ver, dis] = q.top(); q.pop();
      if (st[ver]) continue;
      st[ver] = true; 
      
      for (auto &[v, w]: son[ver]) {
        if (w <= x) {
          chkmin(dist[v], dist[ver]);
          q.push({v, dist[v]});
        } else {
          ll p = (114ll * w + 513) / 514;
          if (p <= x) {
            chkmin(dist[v], dist[ver] + 1);
          q.push({v, dist[v]});
          }
        }
      }

    }
    return dist[t] <= k;
  };

  while (l < r) {
    int mid = (l + r) / 2;
    if (chk(mid)) r = mid;
    else l = mid + 1;
  }

  cout << l << "\n";
  
  


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
