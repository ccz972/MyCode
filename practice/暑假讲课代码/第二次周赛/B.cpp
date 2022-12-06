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
  int T;
  cin >> T;
  while (T--) {
    int n, m, t; cin >> n >> m >> t;
    vector<vector<array<int, 3> > > son(n + 1, vector<array<int, 3> >() );
    int l = 0, r = 0;
    for(int i = 0; i < m; i ++ ) {
      int a, b, c, d; cin >> a >> b >> c >> d;
      son[a].push_back({b, c, d});
      son[b].push_back({a, c, d});
      chkmax(r, c);
    }
    struct node {int ver, dist; bool operator < (const node &T) const {
      return dist > T.dist;
    }};

    auto chk = [&] (int x) {
      priority_queue<node> q;
      vector<int> dist(n + 1, 1e9);
      vector<bool> st(n + 1, false);
      dist[1] = 0;
      q.push({1, 0});
      while(!q.empty()) {
        node t = q.top(); q.pop();
        int ver = t.ver;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = 0; i < son[ver].size(); i ++ ) {
          array<int, 3> res = son[ver][i];
          if(res[1] < x) continue;
          if(dist[res[0]] > dist[ver] + res[2]) {
            dist[res[0]] = dist[ver] + res[2];
            q.push({res[0], dist[res[0]]});
          } 
        }
      }
      return dist[n] <= t;
    };

    while(l < r) {
      int mid = (l + r + 1) / 2;
      if(chk(mid)) l = mid;
      else r = mid - 1;
    }

    cout << l << "\n";
    
  }
  return 0;
}