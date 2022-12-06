#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i(a); i <= b; ++ i)

constexpr int inf = 0x3f3f3f3f;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
void solve() {
  int n, m; cin >> n >> m;
  int sx, sy; cin >> sx >> sy; 
  -- sx, -- sy;
  int xx, yy; cin >> xx >> yy;
  vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
  vector<string> s(n);
  rep(i, 0, n - 1) {
    cin >> s[i];
  }
  deque<array<int, 2> > q;
  vector<vector<int> > dist(n, vector<int> (m, inf));
  vector<vector<bool> > vis(n, vector<bool> (m, false));
  dist[sx][sy] = 0;
  q.push_back({sx, sy});
  while(!q.empty()) {
    array<int, 2> t = q.front(); q.pop_front();
    if(vis[t[0]][t[1]]) continue;    
    vis[t[0]][t[1]] = true;

    rep(i, 0, 3) {
      int x = t[0] + dx[i], y = t[1] + dy[i];
      if(x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '*') continue;
      int w = 0;
      if(!i) w = 1;
      if(dist[x][y] > dist[t[0]][t[1]] + w) {
        dist[x][y] = dist[t[0]][t[1]] + w;
        if(w) q.push_back({x, y});
        else q.push_front({x, y});
      }
    }
  }
  int ret = 0;
  rep(i, 0, n - 1) {
    rep(j, 0, m - 1) {
      //sx - i = b - a
      if(dist[i][j] <= yy && dist[i][j] + sy - j <= xx) {
        ret ++;
      }
    }
  }
  cout << ret;
}