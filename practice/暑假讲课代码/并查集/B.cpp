#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }
  int size(int x) { return siz[leader(x)]; }
};
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while(T -- ) {
    int n, m; cin >> n >> m;
    DSU d(n + 1);
    for(int i = 1; i <= m; i ++ ) {
      int u, v; cin >> u >> v;
      d.merge(u, v);
    }
    set<int> s;
    for(int i = 1; i <= n; i ++ ) {
      s.insert(d.leader(i));
    }
    cout << (int)s.size() << "\n";
  }

  return 0;
}