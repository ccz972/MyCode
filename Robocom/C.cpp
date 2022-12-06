#include <bits/stdc++.h>
using namespace std;

#define chkmax(x, y) x = ((x >= y) ? x : y)

constexpr int INF = 1E9;

struct node {
  int u, distance; 
  bool operator < (const node &T) const {
    return distance > T.distance;
  }
};

void solve() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<int> w(n + 1);
  for(int i = 1; i <= n; i ++ ) cin >> w[i];
  vector<vector<int> > son(n + 1);
  // vector<vector<int> > fson(n + 1);
  for(int i = 1; i <= m; i ++ ) {
    int u, v; cin >> u >> v;
    son[u].push_back(v);
    son[v].push_back(u);
    // fson[v].push_back(u);
  }

  int s, t; cin >> s >> t;

  vector<int> st(n + 1);
  vector<int> dist(n + 1, 1E9);
  priority_queue<node> pq;
  pq.push({s, 0});

  dist[s] = 1;

  while(pq.size()) {
    auto [u, d] = pq.top(); pq.pop();
    if(st[u]) continue;
    st[u] = true;
    for(auto v: son[u]) {
      if(dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        pq.push({v, dist[v]});
      }
    }
  }

  int id = p % k;


  vector<int> f(n + 1, -INF);
  
  if(dist[n] % k == id) {
    f[t] = w[t];
  } else {
    f[t] = 0;
  }

  for(int i = 0; i <= n; i ++ ) st[i] = false;
  
  vector<int> q(m * 2 + 1);
  int hh = 0, tt = 0;
  q[0] = t;


  while(hh <= tt) {
    int u = q[hh ++ ];
    if(st[u]) continue;
    st[u] = true;
    for(auto& v: son[u]) {
      if(dist[v] == dist[u] - 1 && dist[v] < dist[t]) {
        chkmax(f[v], f[u] + (dist[v] % k == id ? w[v] : 0));
        q[++ tt] = v;
      }
    }
  }

  chkmax(f[s], 0);
  cout << f[s];

  //dist[i]表示到i点的最短距离
  
  /*
  跑出来dist[n] 
  然后遍历n的所有出边 v 
  如果有 dist[v] = dist[n] - 1
  ***    有向边   ****
  每个点最多被经过一次 (
  那么v就是一个合法点

  */




}

signed main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr);
  solve();
  return 0;
}