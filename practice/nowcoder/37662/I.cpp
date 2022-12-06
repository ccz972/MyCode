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

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x; cin >> n >> m >> x;
  vector<vector<pair<int, int> > > son(n);
  for (int i = 1, u, v, w; i <= m; i++ ) {
    cin >> u >> v >> w; u --, v --;
    son[u].push_back(make_pair(v, w));
    son[v].push_back(make_pair(u, w));
  }
  struct node { int ver; ll distance; int st; bool operator < (const node &T) const {
    return T.distance < distance;
  }};


  priority_queue<node> q;
  vector<array<ll, 2> > dist(n, {inf, inf});
  vector<vector<bool> > vis(n, vector<bool>(2, false));
  dist[0][1] = 0;
  q.push({0, 0, 1});
  while(q.size()) {
    auto [u, dis, st] = q.top(); q.pop();
    if(vis[u][st]) continue;
    vis[u][st] = true;

    for(auto& [v, w] : son[u]) {
      if(dist[v][st ^ 1] > dist[u][st] + w + (st ? x : 0)) {
        dist[v][st ^ 1] = dist[u][st] + w + (st ? x : 0);
        debug(v, st ^ 1, dist[v][st ^ 1]);
        q.push({v, dist[v][st ^ 1], st ^ 1});
      }
    }
  }
  // cout << dist[2][0] << " " << dist[2][1] << "\n";
  cout << min(dist[n - 1][0], dist[n - 1][1]);
  // auto dist = dijkstra()

  return 0;
}