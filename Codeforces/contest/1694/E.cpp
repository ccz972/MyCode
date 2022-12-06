#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

void solve() {
  int n, m; cin >> n >> m;
  vector<int> deg(n);
  vector son(n, vector<int>());
  for(int i = 0; i < m; i ++ ) {
    int u, v; cin >> u >> v;
    -- u, -- v;
    son[v].push_back(u);    
    deg[u] ++;
  }
  struct node {int ver, d; bool operator < (const node &T) const {
    return d > T.d;
  }};
  priority_queue<node> q;
  vector<int> dist(n, 1e9);
  vector<bool> st(n, false);
  dist[n - 1] = 0;
  q.push({n - 1, 0});
  while(q.size()) {
    auto [ver, d] = q.top(); q.pop();
    if(st[ver]) continue;
    st[ver] = true;
    for(auto v: son[ver]) {
      if(dist[v] > dist[ver] + deg[v]) {
        dist[v] = dist[ver] + deg[v];
        
        q.push({v, dist[v]});
      }
      -- deg[v];
    }
  }
  cout << dist[0];


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int T = 1; cin >> T;
  // while(T -- ) 
  solve();
  return 0;
}