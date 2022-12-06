#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int dist[N], g[N][N];
bool st[N];

int main() {


  int n, m; cin >> n >> m;

  memset(g, 0x3f, sizeof g);
  memset(dist, 0x3f, sizeof dist);

  for(int i = 1; i <= m; i ++ ) {
    int a, b, c; cin >> a >> b >> c;
    //双向边
    if(c < g[a][b]) {
      g[a][b] = g[b][a] = c; 
    }
  }

  dist[1] = 0;

  for(int i = 1; i <= n; i ++ ) {
    int t = 0;
    for(int j = 1; j <= n;  j++ ) {
      if(!st[j] && (!t || dist[j] < dist[t])) {
        t = j;
      }
    }
    st[t] = true;
    for(int j = 1; j <= n; j ++ ) {
      if(dist[j] > dist[t] + g[t][j]) {
        dist[j] = dist[t] + g[t][j];
      }
    }
  }

  cout << dist[n];

  return 0;
}