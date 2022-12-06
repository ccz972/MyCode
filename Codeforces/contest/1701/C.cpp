/***************************************************

@File    : C.cpp
@Time    : 2022/07/08 22:57:01
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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(m);
  vector son(n, vector<int>());
  for(int i = 0; i < m; i ++ ) {
    cin >> a[i];
    son[a[i] - 1].push_back(i);
  }

  int l = 0, r = (m + n - 1) / n * 2;

  auto chk = [&] (int x) {
    vector<bool> vis(m);
    int now = 0;
    for(int i = 0; i < n; i ++ ) {
      for(int j = 0; j < son[i].size() && j < x; j ++ ) {
        vis[son[i][j]] = true;
      }
      if(son[i].size() < x) {
        now += (x - (int)son[i].size()) / 2;
      }
    }
    int cnt = 0;
    for(int i = 0; i < m; i ++ ) if(!vis[i]) {
      cnt ++;
    }
    return cnt <= now;
  };
  
  while(l < r) {
    int mid = (l + r) / 2;
    if(chk(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << "\n";
  
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}