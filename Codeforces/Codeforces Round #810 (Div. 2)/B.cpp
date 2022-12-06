/***************************************************

@File    : B.cpp
@Time    : 2022/07/24 22:40:32
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  auto solve = [&] () {
    int n, m; cin >> n >> m;
    vector<int> a(n), id(n);
    for (auto& x : a) cin >> x;

    iota(id.begin(), id.end(), 0);

    sort(id.begin(), id.end(), [&] (int x, int y) {
       return a[x] < a[y];
    });

    vector<vector<int> > son(n);
    vector<pair<int, int> > b(m);
    vector<int> d(n);
    for(auto& [x, y]: b) {
      cin >> x >> y;
      -- x, -- y;
      if(x > y) swap(x, y);
      d[x] ++; d[y] ++;
      son[x].push_back(y);
    }

    if(~m & 1) {
      cout << "0\n";
      return ;
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i ++ ) {
      if(d[id[i]] & 1) {
        ans = a[id[i]];
        break;
      }
    }
    
    for(int i = 0; i < n; i ++ ) {
      int idx = id[i];
      if(~d[idx] & 1) {
        for(auto& v: son[idx]) {
          if(~d[v] & 1) {
            chkmin(ans, a[idx] + a[v]);
          }
        }
      }
    }

    int ct = 0;
    for(int i = 0; i < n; i ++ )  ct += a[i];
    chkmin(ans, ct);

    cout << ans << "\n";


  };

  int T; cin >> T;
  while (T --) {
    solve();
  }
  return 0;
}