#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 510;
int g[N][N];

struct node {
  int x, y, t;
  bool operator < (const node &T ) const {
    if (t != T.t) return t < T.t;
    if (x != T.x) return x < T.x;
    return y < T.y; 
  }
};

void solve() {
  int n, m, k, q; 
  cin >> n >> m >> k >> q;
  vector<node> a(q);
  int l = 0, r = 1;
  for (int i = 0; i < q; i ++ ) {
    int x, y, t;
    cin >> x >> y >> t;
    a[i] = {x, y, t};
    chkmax(r, t);
  }
  sort(a.begin(), a.end());
  auto chk = [&] (int x) -> bool {

    memset(g, 0, sizeof g);

    for (int i = 0; i < q; i ++ ) {
      if (a[i].t > x) break;
      g[a[i].x][a[i].y] = 1;
    }
    
    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= m; j ++ ) {
        g[i][j] = g[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] ;
      }
    }
    
    for (int i = 1; i + k - 1 <= n; i ++ ) {
      for (int j = 1; j + k - 1 <= m; j ++ ) {
        int mm = i, nn = j, pp = i + k - 1, qq = j + k - 1;
        int ret = g[mm - 1][nn - 1] - g[pp][nn - 1]  - g[mm - 1][qq] + g[pp][qq];
        if (ret == k * k) return true;
      }
    }
    return false;

  };

  if (!chk(r)) {
    cout << "-1\n";
    return;
  }

  while (l < r) {
    int mid = (l + r) / 2;
    if (chk(mid)) r = mid;
    else l = mid + 1;
  }

  cout << l;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}