#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t, s, d;
  while(cin >> t >> s >> d) {

    vector<vector<pair<int, int> > > son(1001);

    for(int i = 1; i <= t; i ++ ) {
      int a, b, c; cin >> a >> b >> c;
      son[a].push_back(make_pair(b, c));
      son[b].push_back(make_pair(a, c));
    }

    for(int i = 0; i < s; i ++ ) {
      int x; cin >> x;
      son[0].push_back(make_pair(x, 0));
    }
    
    vector<int> all;

    for(int i = 0; i < d; i ++ ) {
      int x; cin >> x;
      all.push_back(x);
    }

    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > q;

    vector<bool> st(1001, false);
    vector<int> dist(1001, 0x3f3f3f3f);
    dist[0] = 0;
    q.push(make_pair(0, 0));

    while(!q.empty()) {
      pair<int, int> t = q.top(); q.pop();
      int ver = t.second;
      if(st[ver]) continue;
      st[ver] = true;
      for(auto &x: son[ver]) {
        int dis = x.second, j = x.first;
        if(dist[j] > dist[ver] + dis) {
          dist[j] = dist[ver] + dis;
          q.push(make_pair(dist[j], j));
        }
      }
    }

    int ans = 0x3f3f3f3f;
    for(int i = 0; i < all.size(); i ++ ) {
      ans = min(ans, dist[all[i]]);
    }

    cout << ans << "\n";

  }

  return 0;
}