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
  int n, m; cin >> n >> m;
  //1 1
  map<int, int> mp;
  for (int i = 0; i <= 1001; i ++ ) {
    mp[i * i] = i;
  }
  queue<array<int, 2> > q;
  vector<vector<bool> > vis(n + 1, vector<bool> (n + 1, false));
  vector<vector<int> > dist(n + 1, vector<int> (n + 1, -1));
  q.push({1, 1});
  vis[1][1] = true;
  dist[1][1] = 0;
  while (q.size()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 1; i <= n; i ++ ) {
      //(i, p) (x, y) 
      int res = abs(x - i) * abs(x - i);
      if (res > m) continue;
      res = m - res;
      if (mp.count(res)) {
        int p = mp[res];
        int l = y - p, r = y + p;
        if (l >= 1 && !vis[i][l]) {
          q.push({i, l});
          dist[i][l] = dist[x][y] + 1;
          vis[i][l] = true;
        }
        if (r <= n && !vis[i][r]) {
          q.push({i, r});
          dist[i][r] = dist[x][y] + 1;
          vis[i][r] = true;
        }
      }
    }
  }

  for (int i = 1; i <= n; i ++ ) {
    for (int j = 1; j <= n; j ++ ) {
      cout << dist[i][j] << " \n"[j == n];
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while(T -- ) solve();
  return 0;
}