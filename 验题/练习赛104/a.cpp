#include <bits/stdc++.h>
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, a, b;
  std::cin >> n >> m >> a >> b;
  int ct = 0;
  std::vector<int> cnt(n);
  std::set<int> s;
  for (int i = 0; i < m; i ++ ) {
    int x, y; std::cin >> x >> y;
    -- x;
    if (y == 1) {
      cnt[x] ++;
      ++ ct;
    } else {
      ct = 0;
      cnt[x] = 0;
    }
    
    if (cnt[x] >= b) {
      s.insert(x);
    }
    
    if (ct >= a) {
      s.insert(x);
    }

  }

  std::cout << (int)s.size() << "\n";

  for (int x: s) {
    std::cout << x + 1 << " ";
  }


  return 0;
}