#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }
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


struct Edge {
  int u, v;
} edge[100010];

int main() {
  int n, m; cin >> n >> m;
  DSU d(n * 2 + 1);
  for(int i = 1; i <= m; i ++ ) {
    int u = edge[i].u, v = edge[i].v;
    d.merge(u, v + n); d.merge(v, u + n);
  }

  for(int i = 1; i <= n; i ++ ) {
    if(d.same(i, i + n)) {
      //不是二分图
    }
  }


  return 0;
}