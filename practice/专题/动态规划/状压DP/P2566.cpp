#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 11, M = 1 << N;

int n, m, d; 
int ans, val[M];
char s[N][N];
int f[N][N][M];
bool vis[N][N][M];
int idx[N], idy[N];

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int solve(int nowx, int nowy, int gox, int goy, int state) {
  int res = state;
  for(int i = 0; i < d; i ++ ) {
    if(((nowx == idx[i] && gox > idx[i]) || (nowx > idx[i] && gox == idx[i])) && goy > idy[i]) {
      res ^= (1 << i);
    }
  }
  return res;
}

struct node {
  int x, y, s;
};

void bfs(int S, int e) {
  memset(f, 0x3f, sizeof f);
  memset(vis, false, sizeof vis);
  f[S][e][0] = 0;
  vis[S][e][0] = true;
  queue<node> q;
  q.push({S, e, 0});
  while(!q.empty()) {
    auto t = q.front(); q.pop();
    // debug(S, e);
    for(int i = 0; i < 4; i ++ ) {
      
      int nx = t.x + dx[i], ny = t.y + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m || (isdigit(s[nx][ny]) && s[nx][ny] != '0') || s[nx][ny] == '#') continue;
      int ns = t.s;
      if(i & 1) ns = solve(t.x, t.y, nx, ny, ns);
      if(vis[nx][ny][ns]) continue;
      if(f[nx][ny][ns] > f[t.x][t.y][t.s] + 1) {
        f[nx][ny][ns] = f[t.x][t.y][t.s] + 1;
        vis[nx][ny][ns] = 1;
        q.push({nx, ny, ns});
      }
    }
  }
  for(int i = 0; i < 1 << d; i ++ ) {

    chkmax(ans, val[i] - f[S][e][i]);
  }
  // exit(0);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> d;
  for(int i = 0; i < d; i ++ ) {
    cin >> val[1 << i];
  }

  for(int i = 0; i < 1 << d; i ++) if(!val[i]) {
    for(int j = 0; j < d; j ++ ) if(i >> j & 1) {
      // debug(val[1 << j]);
      val[i] += val[1 << j];
    }
  }

  for(int i = 0; i < n; i ++ ) {
    cin >> s[i];
    for(int j = 0; j < m; j ++ ) if(isdigit(s[i][j]) && s[i][j] > '0') {
      idx[s[i][j] - '1'] = i, idy[s[i][j] - '1'] = j;
    }
  }

  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < m; j ++ ) if(s[i][j] == '0') {
      bfs(i, j);
    }
  }

  cout << ans << "\n";


  return 0;
}