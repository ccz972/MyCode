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

constexpr int N = 1E6 + 10;

struct node {
  int u, v, w;
  bool operator < (const node &T) const {
    return w < T.w;
  }
};

struct DSU {
  std::vector<int> f, siz, rank;
  int c;
  DSU(int n) : c(n), f(n), rank(n, 0), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return -1;
    else -- c;
    if(rank[x] > rank[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
    return y;
  }
  int size(int x) { return siz[find(x)]; }
}; // 按秩合并 + 路径压缩


void solve() {
  int n, m; cin >> n >> m;
  vector<node> a(m);
  vector<int> q;
  for (auto &[u, v, w] : a) {
    cin >> u >> v >> w;
    q.push_back(w);
  }
  if (!n) {
    assert(m == 0);
    return cout << "0\n", void();
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(q.begin(), q.end());
  q.erase(unique(q.begin(), q.end()), q.end());
  int l = 0, r = (int)q.size() - 1;

  auto chk = [&] (int x) -> bool {
    DSU d(n + 1);
    for (int i = 0; i < m; i ++ ) {
      auto [u, v, w] = a[i];
      if (w <= x) break;
      d.merge(u, v);
    }
    for (int i = m - 1; i >= 0; i -- ) {
      auto [u, v, w] = a[i];
      if (w > x) break;
      if (!d.same(u, v)) {
        auto now = d.c - 1;
        if (now - 1 < 2) continue;
        d.merge(u, v);
      }
    }
    // if (d.c == 3) return true;
    return d.c == 3;
  };

  while (l < r) {
    int mid = (l + r) / 2;
    // debug(l, r, mid, q[mid]);
    if (chk(q[mid])) r = mid;
    else l = mid + 1;
  }

  cout << q[l] << "\n";

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
