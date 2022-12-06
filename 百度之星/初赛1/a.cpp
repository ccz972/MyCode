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

constexpr int N = 110;

int g[N][N];
int dist[N][N];
bool st[N][N];

void solve() {
  int n; cin >> n;
  memset(g, 0, sizeof g);
  memset(dist, 0x3f, sizeof dist);
  memset(st, 0, sizeof st);
  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      cin >> g[i][j];
      // dist[i][j] = g[i][j];
    }
  }

  for (int k = 1; k <= n; k ++ ) {
    for (int i = 1; i <= n; i ++ ) {
      for (int j = 1; j <= n; j ++ ) if (i != k && j != k) {
        if (dist[i][j] > min(g[i][k], dist[i][k]) + min(g[k][j], dist[k][j])) {
          dist[i][j] = min(g[i][k], dist[i][k]) + min(g[k][j], dist[k][j]);
        }
      }
    }
  }

  vector<array<int, 2> > ans;
  for(int i = 1; i <= n; i ++ ) {
    for (int j = i + 1; j <= n; j ++ ) if(dist[i][j] > g[i][j]) {
      ans.push_back({i, j});
    }
  }

  cout << (int)ans.size() << "\n";
  for(int i = 0; i < ans.size(); i ++ ) {
    cout << ans[i][0] << " " << ans[i][1] << "\n";
  }
  

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  while(T -- ) solve();
  return 0;
}



















