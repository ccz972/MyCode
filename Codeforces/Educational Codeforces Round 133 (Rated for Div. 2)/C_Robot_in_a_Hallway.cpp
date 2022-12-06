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

constexpr int N = 2E5 + 10;
constexpr ll INF = 1E18;

int n;
int a[2][N];
ll mx1[2][N], mx2[2][N];
bool vis[2][N];

void solve() {
  cin >> n;
  for(int i = 0; i < 2; i ++ ) {
    for(int j = 1; j <= n; j ++ ) {
      cin >> a[i][j]; //++ a[i][j];
      vis[i][j] = false;
    }
    mx1[i][n + 1] = mx2[i][n + 1] = -INF;      
    for(int j = n; j >= 1; j -- ) {
      mx1[i][j] = max(mx1[i][j + 1], (ll)a[i][j] + j);
      mx2[i][j] = max(mx2[i][j + 1], (ll)a[i][j] - j);
      debug(i, j, mx1[i][j], mx2[i][j]);
    }
  }  
  
  vis[0][1] = true;
  ll ans = INF, t = 0;
  for(int x = 0, y = 1; y <= n; ) {
    if(!vis[x ^ 1][y]) {
      ll res = max(t + n - y, mx2[x][y + 1] + n + 1);
      chkmin(ans, max(res + n - y + 1, mx1[x ^ 1][y] - y + 1));
      
      x ^= 1;
    } else {
      ++ y;
    }
    vis[x][y] = true;
    t = max(t + 1, 1ll + a[x][y]);
  }
  chkmin(ans, t);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}