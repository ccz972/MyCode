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

struct node {
  int u, v, t;
  bool operator < (const node &T) const {
    return t < T.t;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;


  vector<node> a(m);
  
  for(int i = 0; i < m; i ++ ) {
    cin >> a[i].u >> a[i].v >> a[i].t;
  }
  
  if(n == 1) {
    cout << "0\n";
    return 0;
  }

  sort(a.begin(), a.end());
  //n, [0, n-1]  n 

  DSU d(n + 10);  

  int ans = -1;

  for(int i = 0; i < m; i ++ ) {
    int u = a[i].u, v = a[i].v, t = a[i].t;
    if(d.same(u, v)) continue;
    d.merge(u, v);
    if(d.size(u) == n) {
      ans = t;
      break;
    }
  }

  cout << ans << "\n";

  return 0;
}