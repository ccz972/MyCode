#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PII pair<int, int>
using namespace std;

const int N = 1e4 + 10, INF = 0x3f3f3f3f;

int n, m; 
int dist[N];
bool st[N];
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra() {
  priority_queue<PII, vector<PII>, greater<PII> > q;
  dist[1] = 0; //起点
  q.push(make_pair(0, 1));
  while(!q.empty()) {
    PII t = q.top(); q.pop();
    int ver = t.second;
    if(st[ver]) continue;
    st[ver] = true;

    //update
    for(int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i], W = w[i];
      if(dist[j] > dist[ver] + W) {
        dist[j] = dist[ver] + W;
        q.push(make_pair(dist[j], j));
      }
    }
  }
  return dist[n];
}

int main() {

  memset(h, -1, sizeof h);
  memset(dist, 0x3f, sizeof dist);

  cin >> n >> m;

  for(int i = 1; i <= m; i ++ ) {
    int a, b, c; cin >> a >> b >> c;
    add(a, b, c); add(b, a, c);
    //双向边
  }

  int ans = dijkstra();

  if(ans == INF) cout << -1;
  else cout << ans << "\n";
  

  return 0;
}