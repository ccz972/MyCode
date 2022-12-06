#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

int dist[110][110];
bool vis[110];
int a[110];
void solve() {
  int n; cin >> n;
  memset(dist, 0x3f, sizeof dist);
  for (int i = 1; i <= n; i ++ ) {
    int x; cin >> x; a[i] = x;
    dist[i][x] = 1;
  }

  for (int k = 1; k <= n; k ++ ) {
    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= n; j ++ ) {
        chkmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int ans = -1;
  rep (t, 1, n) {
    memset(vis, false, sizeof vis);
    rep (i, 1, n) {
      int j = a[i]; int cnt = 0;
      while (j != i && cnt <= 110) {
        cnt ++;
        j = a[j];
      }
      if (cnt <= 100) {
        chkmax(ans, cnt);
      }
    }    
  }
  // if (ans == 1000) ans = -1;
  cout << ans << "\n";

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  // cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
