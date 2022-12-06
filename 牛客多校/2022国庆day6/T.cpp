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

void solve() {
  int n, m, h, q;
  cin >> n >> m >> h >> q;
  vector<vector<vector<vector<int> > > > tr(8, vector<vector<vector<int> > > (n + 1, vector<vector<int> > (m + 1, vector<int>(h + 1, 1E9))));
  
  auto add = [&] (int flag, int x, int y, int z) {
    
    if (flag == 0) {
      //+++
      int res = - x - y - z;
      while (x <= n) {
        while (y <= m) {
          while (z <= h) {
            chkmin(tr[flag][x][y][z], res);
            z += z & -x;
          }
          y += y & -y;
        }
        z += z & -z;
      }
    } else if (flag == 1) {
      //++-
      
    } else if (flag == 2) {
      //+-+

    } else if (flag == 3) {
      //+--

    } else if (flag == 4) {
      //-++

    } else if (flag == 5) {
      //-+-

    } else if (flag == 6) {
      //--+

    } else if (flag == 7) {
      //---
    }
  };

  for (int i = 0; i < q; i ++ ) {
    int op, x, y, z; cin >> op >> x >> y >> z;
    if (op & 1) {

      
    } else {

    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}