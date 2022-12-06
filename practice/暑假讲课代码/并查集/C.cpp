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
  int x, y; 
  while(cin >> x >> y) {
    if(x == -1 && y == -1) break; //最后一组数据，直接break
    //0 0 
    if(!x && !y) {
      cout << "Yes\n";
      continue;
    }

    DSU d(100000 + 1);

    d.merge(x, y);

    bool flag = true; //存储答案的一个布尔值

    set<int> s;
    
    s.insert(x);
    s.insert(y);


    while(cin >> x >> y) {
      if(x == 0 && y == 0) break;

      if(x != y && d.same(x, y)) {
        flag = false;
      }

      s.insert(x);
      s.insert(y);
      d.merge(x, y);
    }

    // set<int> s;
    // for(int p: s)

    for(int p: s) {
      if( ! d.same(p, *s.begin())) {
        flag = false;
      }
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}