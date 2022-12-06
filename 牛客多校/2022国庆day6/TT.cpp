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
  
  auto add = [&] (int flag, int x, int y, int z, int val) {
    for (int i = x; i <= n; i += (i & -i)) {
      for (int j = y; j <= m; j += (j & -j)) {
        for (int k = z; k <= h; k += (k & -k)) {
          chkmin(tr[flag][i][j][k], val);
        }
      }
    }
    
  };

  auto query = [&] (int flag, int x, int y, int z) {
    int ret = 1E9;
    for (int i = x; i > 0; i -= (i & -i)) {
      for (int j = y; j > 0; j -= (j & -j)) {
        for (int k = z; k > 0; k -= (k & -k)) {
          chkmin(ret, tr[flag][i][j][k]);
        }
      }
    }
    return ret;
  };
  
  for (int i = 0; i < q; i ++ ) {
    int op, x, y, z; cin >> op >> x >> y >> z;
    if (op & 1) {
      add(0, x, y, z, - x - y - z);
      add(1, x, y, h - z + 1, - x - y + z);
      add(2, n - x + 1, y, h - z + 1, x - y + z);
      add(3, n - x + 1, y, z, x - y - z);
      add(4, x, m - y + 1, z, - x + y - z);
      add(5, n - x + 1, m - y + 1, z, x + y - z);
      add(6, n - x + 1, m - y + 1, h - z + 1, x + y + z);
      add(7, x, m - y + 1, h - z + 1, - x + y + z);
    } else {
      int ans = 1E9;

      chkmin(ans, x + y + z + query(0, x, y, z));
      chkmin(ans, x + y - z + query(1, x, y, h - z + 1));
      chkmin(ans, - x + y - z + query(2, n - x + 1, y, h - z + 1));
      chkmin(ans, - x + y + z + query(3, n - x + 1, y, z));
      chkmin(ans, x - y + z + query(4, x, m - y + 1, z));
      chkmin(ans, - x - y + z + query(5, n - x + 1, m - y + 1, z));
      chkmin(ans, - x - y - z + query(6, n - x + 1, m - y + 1, h - z + 1));
      chkmin(ans, x - y - z + query(7, x, m - y + 1, h - z + 1));
      cout << ans << endl;
      // cout << ans << "\n";
    }

  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}