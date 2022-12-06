#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 5e5 + 10, INF = 0x3f3f3f3f;

vector<array<int, 2> > son[N];
int n, m, k;
double t, r;
int a[20], dist[20][N];
bool vis[N];
double p[20], dp[20][M];

struct node {
  int ver, dist;
  bool operator < (const node &T) const {
    return T.dist < dist;
  }
};

void dijk(int id, int st) {
  memset(dist[id], 0x3f, sizeof dist[id]);
  memset(vis, false, sizeof vis);
  priority_queue<node> q;
  q.push({st, 0}); dist[id][st] = 0;
  while(q.size()) {
    auto t = q.top(); q.pop();
    int ver = t.ver, distance = t.dist;
    if(vis[ver]) continue;
    vis[ver] = true;
    dist[id][ver] = distance;
    for(auto &[v, w]: son[ver]) {
      if(dist[id][v] > distance + w) {
        dist[id][v] = distance + w;
        q.push({v, dist[id][v]});
      }
    }
  }
}

double dfs(int u, int state) {
  double &ret = dp[u][state];
  if(ret) return ret;
  ret = 1.0 * p[u] * dist[u][n] / t + (1.0 - p[u]) * dist[u][n] / r;
  for(int i = 1; i <= k; i ++ ) {
    if(state >> (i - 1) & 1) continue;
    ret = min(ret, (1.0 - p[u]) * dist[u][n] / r + 
    p[u] * (dist[u][a[i]] / t + dfs(i, state | (1 << (i - 1)))));
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t >> r >> n >> m;
  
  for(int i = 0; i < m; i ++ ) {
    int u, v, w; cin >> u >> v >> w;
    son[u].push_back({v, w});
    son[v].push_back({u, w});
  }

  cin >> k;
  for(int i = 1; i <= k; i ++ ) {
    cin >> a[i] >> p[i]; p[i] /= 100;
    dijk(i, a[i]);
  }

  dijk(19, 1);

  if(dist[19][n] == INF) {
    cout << "-1\n";
  } else {
    p[19] = 1;
    
    cout << fixed << setprecision(10) << dfs(19, 0) << "\n";
  }



  return 0;
}