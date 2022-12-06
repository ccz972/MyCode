/***************************************************

@File    : JJ.cpp
@Time    : 2022/07/25 14:59:17
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

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
#define PII pair<int, int> 
constexpr int N = 500001;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<array<int, 4> > a(n);
  vector<ll> all;
  for(int i = 0; i < n; i ++ ) {
    for(int j = 0; j < 4; j ++ ) {
      cin >> a[i][j];
      -- a[i][j];
      if(~a[i][j])
        all.push_back(1ll * i * N + a[i][j]);
    }
  }

  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  auto find = [&] (ll x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
  };

  array<int, 2> s, t; 
  cin >> s[0] >> s[1] >> t[0] >> t[1];
  -- s[0]; -- s[1]; -- t[0]; -- t[1];

  struct node { int x, y, t; };
  int m = all.size();
  vector<int> dist(m + 1000, -1);
  auto get = [&] (PII x) {
    return 1ll * x.first * N + x.second;
  };
  set<PII > st;
  auto bfs = [&] () {
    deque<node> q;

    node res = {-1, -1, -1};
    for(int i = 0; i < 4; i ++ ) {
      if(s[0] == a[s[1]][i]) {
        res = {s[0], s[1], i};
        break;
      }
    }

    if(res.x == -1) {
      return false;
    }

    q.push_back(res);
    dist[find(get(make_pair(s[0], s[1])))] = 0;

    while(q.size()) {
      auto ttt = q.front(); q.pop_front();
      if(ttt.x == t[0] && ttt.y == t[1]) return true;
      if(st.count({ttt.x, ttt.y})) continue;
      st.insert({ttt.x, ttt.y});

      int k = (ttt.t + 1) % 4;

      for(int i = 0; i < 4; i ++ ) {
        int j = a[ttt.y][i], w = 1;

        if(j == -1) continue;

        if(i == k) w = 0;
        
        PII pres = make_pair(ttt.y, j);
        int nidx = -1;

        for(int l = 0; l < 4; l ++ ) if(ttt.y == a[j][l]) {
          nidx = l;
          break;
        }

        if(nidx == -1) continue;
        ll tmp = get(pres); int id = find(tmp);
        int D = dist[find(get(make_pair(ttt.x, ttt.y)))] + w;
        if(dist[id] == -1 || dist[id] > D) {
          dist[id] =  D;
          if(w) q.push_back({pres.first, pres.second, nidx});
          else q.push_front({pres.first, pres.second, nidx});
        }
      }
    }

    
    return false;


  };
  if(!bfs()) cout << "-1\n";
  else cout << dist[find(get(make_pair(t[0], t[1])))];

  return 0;
}