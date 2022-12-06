#include <bits/stdc++.h>
using namespace std;

const int N = 1010, inf = 0x3f3f3f3f;

struct node {
  int dist, cost;

  bool operator < (const node &T) const {
    if(dist != T.dist) return dist < T.dist;
    return cost < T.cost;
  }

} g[N][N], dist[N] ;

bool st[N];

node operator + (node &a, node &b) {
  node ans = {a.dist + b.dist, a.cost + b.cost};
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  
  int n, m;  //cin >> n >> m;

  node SS = {inf, inf};

  while(cin >> n >> m, n || m) {

    for(int i = 1; i <= n; i ++ ) {
      for(int j = 1; j <= n; j ++ ) {
        g[i][j] = SS;
      }
      dist[i] = SS;
      st[i] = false;
    }

    for(int i = 1; i <= m; i ++ ) {
      int a, b, d, p; cin >> a >> b >> d >> p;
      node now = {d, p};
      if(now < g[a][b]) {
        g[a][b] = g[b][a] = now;
      }
    }

    int s, tt; cin >> s >> tt;

    dist[s] = {0, 0};

    for(int i = 0; i < n; i ++ ) {

      int t = 0;
      for(int j = 1; j <= n; j ++ ) {
        if(!st[j] && (t == 0 || dist[j] < dist[t])) {
          t = j;
        }
      } 

      st[t] = true;

      for(int j = 1; j <= n; j ++ ) {
        if(dist[t] + g[t][j] < dist[j]) {
          dist[j] = dist[t] + g[t][j];
        }
      }
    }

    
    cout << dist[tt].dist << " " << dist[tt].cost << "\n";
  }
  return 0;
}