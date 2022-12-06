#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PII pair<int, int> 

const int N = 1e6 + 10, M = 2e6 + 10;
int n, m; 
int h[N][2], e[M][2], ne[M][2], w[M][2], idx[2];
int dist[N][2];
bool st[N];

void add(int a, int b, int c, int op) {
  e[idx[op]][op] = b, ne[idx[op]][op] = h[a][op], w[idx[op]][op] = c, h[a][op] = idx[op] ++;
}

void dijkstra(int op) {
  priority_queue<PII, vector<PII>, greater<PII> > q;
  for(int i = 0; i <= n; i ++ ) st[i] = false;
  dist[1][op] = 0; //起点
  q.push(make_pair(0, 1));
  while(!q.empty()) {
    PII t = q.top(); q.pop();
    int ver = t.second;
    if(st[ver]) continue;
    st[ver] = true;
    //update
    for(int i = h[ver][op]; i != -1; i = ne[i][op]) {
      int j = e[i][op], W = w[i][op];
      if(dist[j][op] > dist[ver][op] + W) {
        dist[j][op] = dist[ver][op] + W;
        q.push(make_pair(dist[j][op], j));
      }
    }
  }
}

void solve() {
  idx[0] = idx[1] = 0;
  // cin >> n >> m;
  scanf("%d%d", &n, &m);
  
  for(int i = 0; i <= n; i ++ ) {
    h[i][0] = h[i][1] = -1;
    dist[i][0] = dist[i][1] = 0x3f3f3f3f;
  }  

  for(int i = 1; i <= m; i ++ ) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);  //cin >> a >> b >> c;
    add(a, b, c, 0); add(b, a, c, 1);
  }
  dijkstra(0);
  dijkstra(1);
  long long ans = 0;
  for(int i = 1; i <= n; i ++ ) {
    ans += dist[i][0] + dist[i][1];
  }
  printf("%lld\n", ans);
  // cout << ans << "\n";
}

int main() {
  // ios::sync_with_stdio(false); cin.tie(0);
  int T; scanf("%d", &T);
  //cin >> T;
  while (T--) {
    solve();    
  }
  return 0;
}