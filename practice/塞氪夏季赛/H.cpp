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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, int> > > son(n);
  for (int i = 1, u, v, w; i <= m; i++ ) {
    cin >> u >> v >> w; u --, v --;
    son[u].push_back({v, w}), son[v].push_back({u, w});
  }
  struct node {
    int u; ll dis; int k;
    bool operator < (const node &T) const {
      return dis > T.dis;
    }
  };

  priority_queue<node> q;
  vector<vector<bool> > st(n, vector<bool>(k + 1));

  vector<vector<ll> > dist(n, vector<ll>(k + 1, 1E8));
  dist[0][k] = 0;
  q.push({0, 0, k});
  while(q.size()) {
    auto [u, dis, ct] = q.top(); q.pop();
    if(st[u][ct]) continue;
    st[u][ct] = true;
    for(auto& [v, w]: son[u]) {
      if(dist[v][ct] > dist[u][ct] + w) {
        dist[v][ct] = dist[u][ct] + w;
        q.push({v, dist[v][ct], ct});
      } 
      if(!ct) continue;
      if(dist[v][ct - 1] > dist[u][ct]) {
        dist[v][ct - 1] = dist[u][ct];
        q.push({v, dist[v][ct - 1], ct - 1});
      } 
    }
  }

  ll ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());
  cout << ans << "\n";
  

  return 0;
}