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

struct DSU {
  std::vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
  int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return leader(x) == leader(y); }
  bool merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    if (x == y) return false;
    if(x > y) swap(x, y); //x < y 
    siz[y] += siz[x]; //x合并到 y
    f[x] = y;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
}; // 路径压缩

struct edge {
  int u, v;
};

void solve() {
  int n, m, e; cin >> n >> m >> e;

  vector<edge> a(e + 1);

  for(int i = 1; i <= e; i ++ ) {
    int u, v; cin >> u >> v;
    if(u > v) swap(u, v);
    a[i] = {u, v};
  }

  DSU d(n + m + 1);

  int query; cin >> query;

  vector<int> q(query);

  vector<bool> st(e + 1, false);
  
  for(int i = 0; i < query; i ++ ) {
    cin >> q[i];
    st[q[i]] = true;
  }

  for(int i = n + 1; i < n + m; i ++ ) {
    d.merge(i, n + m);
  }

  for(int i = 1; i <= e; i ++ ) if(!st[i]){
    d.merge(a[i].u, a[i].v);
  }

  vector<int> ans(query);

  for(int i = query - 1; i >= 0; i -- ) {
    ans[i] = d.siz[n + m] - m;
    d.merge(a[q[i]].u, a[q[i]].v);
  }

  for(int i = 0; i < query; i ++ ) {
    cout << ans[i] << "\n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- ) solve();
  return 0;
}