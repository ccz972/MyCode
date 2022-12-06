#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int dist[N], g[N][N];
bool st[N];

int main() {


  int n, m; 
  //idx = 0
  while(cin >> n >> m, n || m) {
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    for(int i = 1; i <= m; i ++ ) {
      int a, b, c; cin >> a >> b >> c;
      //双向边
      if(c < g[a][b]) {
        g[a][b] = g[b][a] = c; 
      }
    }

    dist[1] = 0;

    for(int i = 1; i <= 100; i ++ ) {
      int t = 0;
      for(int j = 1; j <= 100;  j++ ) {
        if(!st[j] && (!t || dist[j] < dist[t])) {
          t = j;
        }
      }
      st[t] = true;
      for(int j = 1; j <= 100; j ++ ) {
        if(dist[j] > dist[t] + g[t][j]) {
          dist[j] = dist[t] + g[t][j];
        }
      }
    }

    cout << dist[n] << "\n";

  }

  
  return 0;
}