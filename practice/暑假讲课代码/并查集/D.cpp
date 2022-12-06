#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
// using ll = long long;
#define ll long long

struct DSU {
  vector<int> f, siz;
  DSU(int n) : f(n), siz(n, 1) { for(int i = 0; i < n; i ++ ) f[i] = i; }
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
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  while(cin >> n >> m, n || m) {
    DSU d(n);
    for(int i = 1; i <= m; i ++ ) {
      int k; cin >> k;
      int x; cin >> x;
      for(int j = 1; j < k; j ++ ) {
        int y; cin >> y;
        d.merge(x, y);
      } 
      // int u, v; cin >> u >> v;
      // d.merge(u, v);
    }
    // set<int> s;
    // for(int i = 1; i <= n; i ++ ) {
    //   s.insert(d.leader(i));
    // }
    cout << d.size(0) << "\n";
    // cout << (int)s.size() - 1 << "\n";
    // for(int i )
  }

  return 0;
}