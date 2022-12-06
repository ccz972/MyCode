#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1E3 + 10;


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

struct Point {
  int x, y;
  bool f;
} a[N];

bool echo(Point p, Point q, int d) {
    int xx = p.x - q.x, yy = p.y - q.y;
    //sqrt( (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) ) <= d 

    return (xx * xx + yy * yy <= d * d);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, D; cin >> n >> D;
  for (int i = 1; i <= n; i ++ ) {
    cin >> a[i].x >> a[i].y; a[i].f = false;
  }

  DSU d(n + 1);

  char c; int p, q;

  while (cin >> c) {
    if (c == 'O') {
      cin >> p;
      
      if(a[p].f) continue;
      //p点是被维护过的 
      // 
      for(int i = 1; i <= n; i ++ ) if(i != p && a[i].f && echo(a[i], a[p], D)) {
        d.merge(i, p);
      }

      a[p].f = true;

    } else {
      cin >> p >> q;
      if (d.same(p, q)) {
        cout << "SUCCESS\n";
      } else {
        cout << "FAIL\n";
      }
    }
  }

  return 0;
}