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

constexpr int N = 2e4 + 1;

vector<array<int, 2> > son[N];
int dist[22][N];
bool vis[N];
int dp[1 << 19][22];
int pre[22];

struct node {
  int ver, dis;
  bool operator < (const node &T) const {
    return dis > T.dis;
  }
};

void dijkstra(int st) {
  memset(vis, false, sizeof vis);
  memset(dist[st], 0x3f, sizeof dist[st]);
  dist[st][st] = 0;
  priority_queue<node> q;
  q.push({st, 0});
  while(q.size()) {
    node t = q.top(); q.pop();
    int u = t.ver;
    if(vis[u]) continue;
    vis[u] = true;
    for(auto [v, w]: son[u]) {
      if(dist[st][v] > dist[st][u] + w) {
        dist[st][v] = dist[st][u] + w;
        q.push({v, dist[st][v]});
      }
    }
  }
}

int calc(int x, int j) {
  if((1 << j) > x) return x;
  return ((x >> j + 1) << j) | (x & ((1 << j) - 1));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, m, k; cin >> n >> m >> k;

  for(int i = 1; i <= m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    son[u].push_back({v, w}); son[v].push_back({u, w});
  }
  
  int q; cin >> q;
  
  for(int i = 1; i <= q; ++ i) {
    int r, s; cin >> r >> s;
    pre[s - 2] |= (1 << r - 2);
  }
  //
  if(k == 0) {
    dijkstra(1);
    cout << dist[1][n] << "\n";
    return 0;
  }


  for(int i = 1; i <= k + 1; i ++ ) dijkstra(i);

  memset(dp, 0x3f, sizeof dp);

  dp[0][0] = 0;

  for(int i = 1; i <= k; ++ i) if(!pre[i - 1]) dp[0][i] = dist[1][i + 1];
  

  for(int i = 1; i < 1 << k; i ++ ) {
    for(int j = 0; j < k; j ++ ) if(i >> j & 1) {
      int tmp1 = calc(i, j);
      for(int l = 0; l < k; l ++ ) if((not (i >> l & 1)) && ( (i & pre[l]) == pre[l])) {
        int tmp2 = calc(i, l);
        dp[tmp2][l + 1] = min(dp[tmp1][j + 1] + dist[j + 2][l + 2], dp[tmp2][l + 1]);
        //2 -> 1
      }
    }
  }

  int S = (1 << k) - 1;

  int ans = INT_MAX;
  for(int i = 1; i <= k; i ++ ) {
    int tmp = calc(S, i - 1);
    ans = min(ans, dp[tmp][i] + dist[i + 1][n]);
  }

  cout << ans << "\n";

  return 0;
}